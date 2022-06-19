/*
** EPITECH PROJECT, 2022
** SystemEvent
** File description:
** SystemEvent
*/

#include "SystemEvent.hpp"
#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include "core/information/info.hpp"
#include "core/winMenu.hpp"
#include "raylib/include/Gamepad.hpp"

namespace ecs
{
    static bool isClicking(raylib::Rectangle &rectangle)
    {
        raylib::Mouse mouseIndex;
        if ((mouseIndex.GetX() >= rectangle.x) && (mouseIndex.GetY() >= rectangle.y) && (mouseIndex.GetX() < rectangle.x + rectangle.width)
            && (mouseIndex.GetY() < rectangle.height + rectangle.y)) {
            return (true);
        }
        return (false);
    }

    bool SystemEvent::_isControllerAssign(ecs::Core &core, int gamepadNumber)
    {
        for (auto *it : core.getEntities()) {
            if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() == gamepadNumber)
                return (true);
        }
        return (false);
    }

    bool SystemEvent::_assignController(ecs::Core &core, int gamepadNumber)
    {
        if (_isControllerAssign(core, gamepadNumber))
            return (false);
        for (auto *it : core.getEntities()) {
            if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() == -1) {
                it->get<ComponentControllable>()->setGamepadId(gamepadNumber);
                if (it->has<ComponentDrawable>())
                    it->get<ComponentDrawable>()->setIsDrawable3D(true);
                if (it->has<ComponentTexture>()) {
                    it->get<ComponentTexture>()->setTexture("assets/connectPlayers/IconValidate.png");
                    it->get<ComponentTexture>()->setPos(it->get<ComponentTexture>()->getPos2());
                }
                return (true);
            }
        }
        return (false);
    }

    void SystemEvent::_reassignControllers(ecs::Core &core)
    {
        static int nbGamepadTmp = 0;

        if (raylib::Gamepad::gamepadNumber >= nbGamepadTmp)
            return;
        for (auto *it : core.getEntities()) {
            for (int i = nbGamepadTmp; i > raylib::Gamepad::gamepadNumber; i--) {
                if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() == i) {
                    it->get<ComponentControllable>()->setGamepadId(-1);
                    if (it->has<ComponentDrawable>()) {
                        it->get<ComponentDrawable>()->setIsDrawable2D(true);
                        it->get<ComponentDrawable>()->setIsDrawable3D(false);
                    }
                    if (it->has<ComponentModel>())
                        it->get<ComponentModel>()->setRotateAngle(180.0f);
                    if (it->has<ComponentTexture>()) {
                        it->get<ComponentTexture>()->setTexture(it->get<ComponentTexture>()->getPathOldTexture());
                        it->get<ComponentTexture>()->setPos(it->get<ComponentTexture>()->getOldPos());
                    }
                }
            }
        }
    }

    int SystemEvent::_nbControllersAssign(ecs::Core &core)
    {
        int nb = 0;

        for (auto *it : core.getEntities()) {
            if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() != -1) {
                nb++;
            }
        }
        return (nb);
    }

    void SystemEvent::_detectNbControllers()
    {
        if (!raylib::Gamepad::IsAvailable(0))
            raylib::Gamepad::gamepadNumber--;
        if (!raylib::Gamepad::IsAvailable(1))
            raylib::Gamepad::gamepadNumber--;
        if (!raylib::Gamepad::IsAvailable(2))
            raylib::Gamepad::gamepadNumber--;
        if (!raylib::Gamepad::IsAvailable(3))
            raylib::Gamepad::gamepadNumber--;
    }

    void SystemEvent::_resetStateButtons(ecs::Core &core, int idButton)
    {
        for (auto *it : core.getEntities()) {
            if (it->has<ComponentButton>() && it->get<ComponentButton>()->getIdButton() != idButton)
                it->get<ComponentButton>()->setState(false);
        }
    }

    void SystemEvent::_handleButtonsMoveUpDown(ecs::Core &core, int upOrDown)
    {
        static int tmpIdButton = 0;
        int idMax = 0;
        bool isId = false;

        for (auto *it : core.getEntities()) {
            if (it->has<ComponentButton>()) {
                if (it->get<ComponentButton>()->getIdButton() > idMax)
                    idMax = it->get<ComponentButton>()->getIdButton();
                if (it->get<ComponentButton>()->getIdButton() == tmpIdButton + upOrDown) {
                    isId = true;
                    break;
                }
            }
        }
        if (upOrDown > 0 && !isId)
            tmpIdButton = -1;
        else if (upOrDown < 0 && !isId)
            tmpIdButton = idMax + 1;
        for (auto *it : core.getEntities()) {
            if (it->has<ComponentButton>() && it->get<ComponentButton>()->getIdButton() == tmpIdButton + upOrDown) {
                it->get<ComponentButton>()->setState(true);
                tmpIdButton = it->get<ComponentButton>()->getIdButton();
                _resetStateButtons(core, it->get<ComponentButton>()->getIdButton());
                break;
            }
        }
    }

    void SystemEvent::_handleMouseMenu(ecs::Core &core)
    {
        int i = 0;
        raylib::Mouse mouseIndex;

        for (std::size_t j = 0; i < core.getNbButtons(); j++) {
            if (core.getEntity(j)->has<ComponentButton>()) {
                core.getEntity(j)->get<ComponentButton>()->setState(false);
                raylib::Rectangle buttonTmp = raylib::Rectangle(core.getEntity(j)->get<ComponentButton>()->getPos().x,
                    core.getEntity(j)->get<ComponentButton>()->getPos().y, core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->width,
                    core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->height);
                if (isClicking(buttonTmp) == true && i == 0) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        if (core.getEntity("SoundClick") != nullptr)
                            core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                        core.setScene(ecs::Scenes::ConnectPlayers);
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 1) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        core.setStartMode(ecs::GameStartMode::Load);
                        if (core.getEntity("SoundClick") != nullptr)
                            core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                        core.setScene(ecs::Scenes::Game);
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 2) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        if (core.getEntity("SoundClick") != nullptr)
                            core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                        core.setScene(ecs::Scenes::Close);
                        return;
                    }
                }
                i++;
            }
        }
    }

    void SystemEvent::handleControllersMenu(ecs::Core &core)
    {
        static std::chrono::time_point<std::chrono::system_clock> elapsedTimeToMoveButtons = std::chrono::system_clock::now();

        if (raylib::Gamepad::IsAvailable(0)) {
            if (raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonRightFaceDown())) {
                for (auto *it : core.getEntities()) {
                    if (it->has<ComponentButton>() && it->get<ComponentButton>()->getState()) {
                        if (it->get<ComponentButton>()->getIdButton() == 0) {
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::ConnectPlayers);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 1) {
                            core.setStartMode(ecs::GameStartMode::Load);
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::Game);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 2) {
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::Close);
                            return;
                        }
                        break;
                    }
                }
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == 1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceDown())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, 1);
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == -1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceUp())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, -1);
            }
        } else
            _handleMouseMenu(core);
    }

    void SystemEvent::_handleMouseConnectPlayer(ecs::Core &core)
    {
        int i = 0;
        raylib::Mouse mouseIndex;

        for (std::size_t j = 0; i < core.getNbButtons(); j++) {
            if (core.getEntity(j)->has<ComponentButton>()) {
                core.getEntity(j)->get<ComponentButton>()->setState(false);
                raylib::Rectangle buttonTmp = raylib::Rectangle(core.getEntity(j)->get<ComponentButton>()->getPos().x,
                    core.getEntity(j)->get<ComponentButton>()->getPos().y, core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->width,
                    core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->height);
                if (isClicking(buttonTmp) == true && i == 0) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        if (core.getEntity("SoundClick") != nullptr)
                            core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                        core.setScene(ecs::Scenes::Menu);
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 2) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        core.setStartMode(ecs::GameStartMode::Restart);
                        core.setScene(ecs::Scenes::GameSettings);
                        if (core.getEntity("SoundClick") != nullptr)
                            core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                        return;
                    }
                }
                i++;
            }
        }
    }

    void SystemEvent::_connectingPlayers(ecs::Core &core)
    {
        bool noButtonAvailable = false;

        if (!raylib::Gamepad::IsAvailable(0)) {
            _handleMouseConnectPlayer(core);
            return;
        }
        for (auto *it : core.getEntities()) {
            if (it->has<ComponentButton>() && it->get<ComponentButton>()->getState() && it->get<ComponentButton>()->getIdButton() == 1)
                noButtonAvailable = true;
        }
        _reassignControllers(core);
        for (int i = 0; i <= raylib::Gamepad::gamepadNumber; i++) {
            if (raylib::Gamepad::IsAvailable(i)) {
                if (noButtonAvailable && raylib::Gamepad::IsButtonReleased(i, raylib::Gamepad::GamepadButtonRightFaceDown()))
                    _assignController(core, i);
                for (auto *it : core.getEntities()) {
                    if (it->has<ComponentButton>() && it->get<ComponentButton>()->getIdButton() == -core.getNbButtons() + 1 && _nbControllersAssign(core) > 0)
                        it->get<ComponentButton>()->setIdButton(-it->get<ComponentButton>()->getIdButton());
                    else if (it->has<ComponentButton>() && it->get<ComponentButton>()->getIdButton() == core.getNbButtons() - 1
                        && _nbControllersAssign(core) <= 0)
                        it->get<ComponentButton>()->setIdButton(-it->get<ComponentButton>()->getIdButton());
                    if (it->has<ComponentModel>())
                        it->get<ComponentModel>()->Update(0);
                    if (it->has<ComponentModel>() && (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() == i)) {
                        if (it->get<ComponentModel>()->getRotateAngle() == 360.0f)
                            it->get<ComponentModel>()->setRotateAngle(0.0f);
                        it->get<ComponentModel>()->setRotateAngle(
                            it->get<ComponentModel>()->getRotateAngle() + (raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisLeftX()) * 0.3f));
                    }
                }
            }
        }
    }

    void SystemEvent::handleControllersConnectPlayers(ecs::Core &core)
    {
        static std::chrono::time_point<std::chrono::system_clock> elapsedTimeToMoveButtons = std::chrono::system_clock::now();

        if (raylib::Gamepad::IsAvailable(0)) {
            if (raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonRightFaceDown())) {
                for (auto *it : core.getEntities()) {
                    if (it->has<ComponentButton>() && it->get<ComponentButton>()->getState()) {
                        if (it->get<ComponentButton>()->getIdButton() == 0) {
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::Menu);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 2) {
                            core.setStartMode(ecs::GameStartMode::Restart);
                            core.setScene(ecs::Scenes::GameSettings);
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            return;
                        }
                        break;
                    }
                }
            }
            if (raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonRightFaceRight())) {
                core.setScene(ecs::Scenes::Menu);
                return;
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == 1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceDown())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, 1);
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == -1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceUp())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, -1);
            }
        }
        _connectingPlayers(core);
    }

    void SystemEvent::_handleMousePause(ecs::Core &core)
    {
        int i = 0;
        raylib::Mouse mouseIndex;

        for (std::size_t j = 0; i < core.getNbButtons(); j++) {
            if (core.getEntity(j)->has<ComponentButton>() && core.getEntity(j)->get<ComponentButton>()->getState()) {
                core.getEntity(j)->get<ComponentButton>()->setState(false);
                raylib::Rectangle *buttonTmp = new raylib::Rectangle(core.getEntity(j)->get<ComponentButton>()->getPos().x,
                    core.getEntity(j)->get<ComponentButton>()->getPos().y, core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->width,
                    core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->height);
                if (isClicking(*buttonTmp) == true && i == 0) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        core.setScene(ecs::Scenes::Game);
                } else if (isClicking(*buttonTmp) == true && i == 1) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        core.setScene(ecs::Scenes::GameSave);
                } else if (isClicking(*buttonTmp) == true && i == 2) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        core.setScene(ecs::Scenes::Menu);
                } else if (isClicking(*buttonTmp) == true && i == 3) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        core.setScene(ecs::Scenes::Close);
                }
                i++;
            }
        }
    }

    void SystemEvent::handleControllersPause(ecs::Core &core)
    {
        static std::chrono::time_point<std::chrono::system_clock> elapsedTimeToMoveButtons = std::chrono::system_clock::now();

        if (raylib::Gamepad::IsAvailable(0)) {
            if (raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonRightFaceDown())) {
                for (auto *it : core.getEntities()) {
                    if (it->has<ComponentButton>() && it->get<ComponentButton>()->getState()) {
                        if (it->get<ComponentButton>()->getIdButton() == 0) {
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::Game);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 1) {
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::GameSave);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 2) {
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::Menu);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 3) {
                            if (core.getEntity("SoundClick") != nullptr)
                                core.getEntity("SoundClick")->get<ComponentSound>()->getSound().PlayMulti();
                            core.setScene(ecs::Scenes::Close);
                            return;
                        }
                        break;
                    }
                }
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == 1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceDown())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, 1);
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == -1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceUp())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, -1);
            }
        } else
            _handleMousePause(core);
    }

    void SystemEvent::_handleMovementPlayers(ecs::IEntity *it, int idController)
    {
        if (raylib::Gamepad::GetAxisMovement(idController, raylib::Gamepad::GamepadAxisLeftX()) > 0.3) {
            it->get<ComponentModel>()->setRotateAngle(ComponentMovable::RIGHT);
            it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::RIGHT);
        }
        if (raylib::Gamepad::GetAxisMovement(idController, raylib::Gamepad::GamepadAxisLeftX()) < -0.3) {
            it->get<ComponentModel>()->setRotateAngle(ComponentMovable::LEFT);
            it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::LEFT);
        }
        if (raylib::Gamepad::GetAxisMovement(idController, raylib::Gamepad::GamepadAxisLeftY()) > 0.3) {
            it->get<ComponentModel>()->setRotateAngle(ComponentMovable::DOWN);
            it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::DOWN);
        }
        if (raylib::Gamepad::GetAxisMovement(idController, raylib::Gamepad::GamepadAxisLeftY()) < -0.3) {
            it->get<ComponentModel>()->setRotateAngle(ComponentMovable::UP);
            it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::UP);
        }
        if (it->has<ComponentCollider>() && !it->get<ComponentCollider>()->getIsAbleToCollide()) {
            if (std::chrono::system_clock::now() - it->get<ComponentCollider>()->getTimeNonCollide() >= std::chrono::seconds(4)) {
                it->get<ComponentModel>()->setPos(raylib::Vector3(
                    it->get<ComponentModel>()->getInitialPos().x, it->get<ComponentModel>()->getInitialPos().y, it->get<ComponentModel>()->getInitialPos().z));
                it->get<ComponentCollider>()->setIsAbleToCollide(true);
            }
        }
    }

    void SystemEvent::_handleCollisions(ecs::Core &core, ecs::IEntity *it, int idController)
    {
        if (it->has<ComponentCollider>()) {
            float axis_x = raylib::Gamepad::GetAxisMovement(idController, raylib::Gamepad::GamepadAxisLeftY());
            float axis_z = raylib::Gamepad::GetAxisMovement(idController, raylib::Gamepad::GamepadAxisLeftX());
            it->get<ComponentModel>()->setPos(raylib::Vector3(it->get<ComponentModel>()->getPos().x - axis_x * it->get<ComponentMovable>()->getSpeed(),
                it->get<ComponentModel>()->getPos().y, it->get<ComponentModel>()->getPos().z + axis_z * it->get<ComponentMovable>()->getSpeed()));
            raylib::BoundingBox box(raylib::Vector3(it->get<ComponentModel>()->getPos().x - 0.27, it->get<ComponentModel>()->getPos().y,
                                        it->get<ComponentModel>()->getPos().z - 0.27),
                raylib::Vector3(
                    it->get<ComponentModel>()->getPos().x + 0.27, it->get<ComponentModel>()->getPos().y + 1, it->get<ComponentModel>()->getPos().z + 0.27));
            if (SystemCollision::checkCollisions(box, it, core.getEntities())) {
                it->get<ComponentModel>()->setPos(raylib::Vector3(it->get<ComponentModel>()->getPos().x + axis_x * it->get<ComponentMovable>()->getSpeed(),
                    it->get<ComponentModel>()->getPos().y, it->get<ComponentModel>()->getPos().z - axis_z * it->get<ComponentMovable>()->getSpeed()));
            }
        }
    }

    void SystemEvent::_handlePickBoosts(ecs::Core &core, ecs::IEntity *it)
    {
        raylib::BoundingBox box(
            raylib::Vector3(it->get<ComponentModel>()->getPos().x - 0.27, it->get<ComponentModel>()->getPos().y, it->get<ComponentModel>()->getPos().z - 0.27),
            raylib::Vector3(
                it->get<ComponentModel>()->getPos().x + 0.27, it->get<ComponentModel>()->getPos().y + 1, it->get<ComponentModel>()->getPos().z + 0.27));
        SystemCollision::checkCollisionsBoosts(box, it, core.getEntities());
    }

    void SystemEvent::_handleBombPlayer(ecs::Core &core, ecs::IEntity *it)
    {
        raylib::BoundingBox box(
            raylib::Vector3(it->get<ComponentModel>()->getPos().x - 0.27, it->get<ComponentModel>()->getPos().y, it->get<ComponentModel>()->getPos().z - 0.27),
            raylib::Vector3(
                it->get<ComponentModel>()->getPos().x + 0.27, it->get<ComponentModel>()->getPos().y + 1, it->get<ComponentModel>()->getPos().z + 0.27));
        SystemCollision::checkCollisionsBomb(box, it, core.getEntities());
    }

    void SystemEvent::_handleBombBox(ecs::Core &core, ecs::IEntity *it)
    {
        raylib::BoundingBox box(
            raylib::Vector3(it->get<ComponentCube>()->getPos().x - 0.5, it->get<ComponentCube>()->getPos().y - 0.5, it->get<ComponentCube>()->getPos().z - 0.5),
            raylib::Vector3(
                it->get<ComponentCube>()->getPos().x + 0.5, it->get<ComponentCube>()->getPos().y + 0.5, it->get<ComponentCube>()->getPos().z + 0.5));
        SystemCollision::checkCollisionsBomb(box, it, core.getEntities());
    }

    void SystemEvent::handleControllersGame(ecs::Core &core)
    {
        raylib::Mouse mouseIndex;
        int j = 0;
        int k = 0;

        if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
            core.setScene(ecs::Scenes::Pause);
            return;
        }
        for (int i = 0; i <= raylib::Gamepad::gamepadNumber; i++) {
            if (raylib::Gamepad::IsAvailable(i) && _isControllerAssign(core, i)) {
                if (raylib::Gamepad::IsButtonReleased(i, raylib::Gamepad::GamepadButtonMiddleRight())) {
                    core.setScene(ecs::Scenes::Pause);
                    return;
                }
                for (auto *e : core.getEntities()) {
                    if (e->has<ComponentKills>()) {
                        if (e->get<ComponentDrawable>()->getIsDrawable3D() == true)
                            j++;
                        k++;
                    }
                }
                if (j == 0 && k != 0) {
                    core.setScene(ecs::Scenes::Win);
                    return;
                } else if (j == 1) {
                    core.setScene(ecs::Scenes::Win);
                    return;
                }
                for (auto *it : core.getEntities()) {
                    if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() == i
                        && it->get<ComponentDrawable>()->getIsDrawable3D()) {
                        _handleMovementPlayers(it, i);
                        _handleCollisions(core, it, i);
                        _handlePickBoosts(core, it);
                        _handleBombPlayer(core, it);
                        updateInformations(core, it);
                        if (raylib::Gamepad::IsButtonReleased(i, raylib::Gamepad::GamepadButtonRightFaceDown()) && it->has<ComponentBombs>()
                            && it->get<ComponentBombs>()->getNbMaxBombs() > it->get<ComponentBombs>()->getNbCurrBombs()) {
                            ecs::IEntity *bomb1 = new ecs::IEntity;
                            bomb1->add<ComponentDrawable>(false, true);
                            bomb1->add<ComponentExplosion>(it->getLabel());
                            bomb1->add<ComponentModel>("assets/models3D/Bomb.obj",
                                raylib::Vector3(std::roundf(it->get<ComponentModel>()->getPos().x), std::roundf(it->get<ComponentModel>()->getPos().y),
                                    std::roundf(it->get<ComponentModel>()->getPos().z)));
                            core.addEntity(bomb1);
                            it->get<ComponentBombs>()->setNbCurrBombs(it->get<ComponentBombs>()->getNbCurrBombs() + 1);
                        }
                    }
                }
            }
        }
        for (auto *it : core.getEntities()) {
            if (it->has<ComponentKillable>() && it->has<ComponentCube>() && it->get<ComponentDrawable>()->getIsDrawable3D()) {
                _handleBombBox(core, it);
            }
            if (it->has<ComponentKills>() && !it->has<ComponentControllable>() && it->get<ComponentDrawable>()->getIsDrawable3D()) {
                _handlePickBoosts(core, it);
                _handleBombPlayer(core, it);
                updateInformations(core, it);
            }
        }
    }

    void SystemEvent::_handleMouseSettings(ecs::Core &core)
    {
        int i = 0;
        raylib::Mouse mouseIndex;

        for (std::size_t j = 0; i < core.getNbButtons(); j++) {
            if (core.getEntity(j)->has<ComponentButton>()) {
                core.getEntity(j)->get<ComponentButton>()->setState(false);
                raylib::Rectangle buttonTmp = raylib::Rectangle(core.getEntity(j)->get<ComponentButton>()->getPos().x,
                    core.getEntity(j)->get<ComponentButton>()->getPos().y, core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->width,
                    core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->height);
                if (isClicking(buttonTmp) == true && i == 0) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        int nbBot = std::stoi(core.getEntity(j + 1)->get<ComponentText>()->getText());
                        if (nbBot < 4 - nbController)
                            nbBot++;
                        core.getEntity(j + 1)->get<ComponentText>()->setText(std::to_string(nbBot));
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 1) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        int nbBot = std::stoi(core.getEntity(j - 1)->get<ComponentText>()->getText());
                        if (nbBot > 0)
                            nbBot--;
                        core.getEntity(j - 1)->get<ComponentText>()->setText(std::to_string(nbBot));
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 2) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        int nbBomb = std::stoi(core.getEntity(j + 1)->get<ComponentText>()->getText()) + 1;
                        core.getEntity(j + 1)->get<ComponentText>()->setText(std::to_string(nbBomb));
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 3) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        int nbBomb = std::stoi(core.getEntity(j - 1)->get<ComponentText>()->getText());
                        if (nbBomb > 1)
                            nbBomb--;
                        core.getEntity(j - 1)->get<ComponentText>()->setText(std::to_string(nbBomb));
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 4) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        if (core.getEntity(j + 1)->get<ComponentText>()->getText().compare("yes") == 0)
                            core.getEntity(j + 1)->get<ComponentText>()->setText("no");
                        else
                            core.getEntity(j + 1)->get<ComponentText>()->setText("yes");
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 5) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        core.setScene(ecs::Scenes::Game);
                } else if (isClicking(buttonTmp) == true && i == 6) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        core.setScene(ecs::Scenes::ConnectPlayers);
                }
                i++;
            }
        }
    }

    void SystemEvent::handleControllersGameSettings(ecs::Core &core)
    {
        int i = 0;
        static std::chrono::time_point<std::chrono::system_clock> elapsedTimeToMoveButtons = std::chrono::system_clock::now();

        if (raylib::Gamepad::IsAvailable(0)) {
            if (raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonRightFaceDown())) {
                for (std::size_t j = 0; i < core.getNbButtons(); j++) {
                    if (core.getEntity(j)->has<ComponentButton>() && core.getEntity(j)->get<ComponentButton>()->getState()) {
                        if (core.getEntity(j)->get<ComponentButton>()->getIdButton() == 0) {
                            int nbBot = std::stoi(core.getEntity(j + 1)->get<ComponentText>()->getText());
                            if (nbBot < 4 - nbController)
                                nbBot++;
                            core.getEntity(j + 1)->get<ComponentText>()->setText(std::to_string(nbBot));
                            return;
                        } else if (core.getEntity(j)->get<ComponentButton>()->getIdButton() == 1) {
                            int nbBot = std::stoi(core.getEntity(j - 1)->get<ComponentText>()->getText());
                            if (nbBot > 0)
                                nbBot--;
                            core.getEntity(j - 1)->get<ComponentText>()->setText(std::to_string(nbBot));
                            return;
                        } else if (core.getEntity(j)->get<ComponentButton>()->getIdButton() == 2) {
                            int nbBomb = std::stoi(core.getEntity(j + 1)->get<ComponentText>()->getText()) + 1;
                            core.getEntity(j + 1)->get<ComponentText>()->setText(std::to_string(nbBomb));
                            return;
                        } else if (core.getEntity(j)->get<ComponentButton>()->getIdButton() == 3) {
                            int nbBomb = std::stoi(core.getEntity(j - 1)->get<ComponentText>()->getText());
                            if (nbBomb > 1)
                                nbBomb--;
                            core.getEntity(j - 1)->get<ComponentText>()->setText(std::to_string(nbBomb));
                            return;
                        } else if (core.getEntity(j)->get<ComponentButton>()->getIdButton() == 4) {
                            if (core.getEntity(j + 1)->get<ComponentText>()->getText().compare("yes") == 0)
                                core.getEntity(j + 1)->get<ComponentText>()->setText("no");
                            else
                                core.getEntity(j + 1)->get<ComponentText>()->setText("yes");
                            return;
                        } else if (core.getEntity(j)->get<ComponentButton>()->getIdButton() == 5) {
                            core.setScene(ecs::Scenes::Game);
                            return;
                        } else if (core.getEntity(j)->get<ComponentButton>()->getIdButton() == 6) {
                            core.setScene(ecs::Scenes::ConnectPlayers);
                            return;
                        }
                        i++;
                    }
                }
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == 1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceDown())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, 1);
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == -1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceUp())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, -1);
            }
        } else
            _handleMouseSettings(core);
    }

    void SystemEvent::handleControllersWin(ecs::Core &core)
    {
        (void)core;
        static std::chrono::time_point<std::chrono::system_clock> elapsedTimeToMoveButtons = std::chrono::system_clock::now();

        if (raylib::Gamepad::IsAvailable(0)) {
            if (raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonRightFaceDown())) {
                for (auto *it : core.getEntities()) {
                    if (it->has<ComponentButton>() && it->get<ComponentButton>()->getState()) {
                        core.setScene(ecs::Scenes::Menu);
                        return;
                    }
                }
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == 1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceDown())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, 1);
            }
            if (((std::chrono::system_clock::now() - elapsedTimeToMoveButtons >= std::chrono::milliseconds(200))
                    && raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == -1)
                || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceUp())) {
                elapsedTimeToMoveButtons = std::chrono::system_clock::now();
                _handleButtonsMoveUpDown(core, -1);
            }
        }
    }

    void SystemEvent::update(ecs::Core &core)
    {
        raylib::Gamepad::gamepadNumber = 3;
        _detectNbControllers();
        switch (core.getScene()) {
            case ecs::Scenes::Menu: handleControllersMenu(core); break;
            case ecs::Scenes::ConnectPlayers: handleControllersConnectPlayers(core); break;
            case ecs::Scenes::Game: handleControllersGame(core); break;
            case ecs::Scenes::Pause: handleControllersPause(core); break;
            case ecs::Scenes::GameSettings: handleControllersGameSettings(core); break;
            case ecs::Scenes::Win: handleControllersWin(core); break;
            default: break;
        }
    }
} // namespace ecs
