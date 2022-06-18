/*
** EPITECH PROJECT, 2022
** SystemEvent
** File description:
** SystemEvent
*/

#include "SystemEvent.hpp"
#include <chrono>
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

        for (size_t j = 0; i < core.getNbButtons(); j++) {
            if (core.getEntity(j)->has<ComponentButton>()) {
                core.getEntity(j)->get<ComponentButton>()->setState(false);
                raylib::Rectangle buttonTmp = raylib::Rectangle(core.getEntity(j)->get<ComponentButton>()->getPos().x,
                    core.getEntity(j)->get<ComponentButton>()->getPos().y, core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->width,
                    core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->height);
                if (isClicking(buttonTmp) == true && i == 0) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        core.setScene(ecs::Scenes::ConnectPlayers);
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 1) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        core.setScene(ecs::Scenes::Game);
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 2) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
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
                            core.setScene(ecs::Scenes::ConnectPlayers);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 1) {
                            core.setScene(ecs::Scenes::Game);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 2) {
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

        for (size_t j = 0; i < core.getNbButtons(); j++) {
            if (core.getEntity(j)->has<ComponentButton>()) {
                core.getEntity(j)->get<ComponentButton>()->setState(false);
                raylib::Rectangle buttonTmp = raylib::Rectangle(core.getEntity(j)->get<ComponentButton>()->getPos().x,
                    core.getEntity(j)->get<ComponentButton>()->getPos().y, core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->width,
                    core.getEntity(j)->get<ComponentButton>()->getRectangleActive()->height);
                if (isClicking(buttonTmp) == true && i == 0) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        core.setScene(ecs::Scenes::Menu);
                        return;
                    }
                } else if (isClicking(buttonTmp) == true && i == 2) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft())) {
                        core.setScene(ecs::Scenes::Game);
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
                            core.setScene(ecs::Scenes::Menu);
                            return;
                        }
                        if (it->get<ComponentButton>()->getIdButton() == 2) {
                            core.setScene(ecs::Scenes::Game);
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
        }
        _connectingPlayers(core);
    }

    void SystemEvent::_handleMousePause(ecs::Core &core)
    {
        int i = 0;
        raylib::Mouse mouseIndex;

        for (size_t j = 0; i < core.getNbButtons(); j++) {
            if (core.getEntity(j)->has<ComponentButton>()) {
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
                        core.setScene(ecs::Scenes::Close);
                } else if (isClicking(*buttonTmp) == true && i == 2) {
                    core.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        core.setScene(ecs::Scenes::Close);
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
        _handleMousePause(core);
    }

    void SystemEvent::handleControllersGame(ecs::Core &core)
    {
        for (int i = 0; i <= raylib::Gamepad::gamepadNumber; i++) {
            if (raylib::Gamepad::IsAvailable(i) && _isControllerAssign(core, i)) {
                // Draw buttons: xbox home
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddle()))
                    std::cout << "home" << std::endl;

                // Draw buttons: basic
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddleRight()))
                    std::cout << "start" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddleLeft()))
                    std::cout << "select" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceRight()))
                    std::cout << "O" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceDown()))
                    std::cout << "X" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceLeft()))
                    std::cout << "[]" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceUp()))
                    std::cout << "/\\" << std::endl;

                // Draw buttons: d-pad
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceUp()))
                    std::cout << "up" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceDown()))
                    std::cout << "down" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceLeft()))
                    std::cout << "left" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceRight()))
                    std::cout << "right" << std::endl;

                // Draw buttons: left-right back
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftTrigger1()))
                    std::cout << "a" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightTrigger1()))
                    std::cout << "b" << std::endl;

                // Draw axis: left joystick
                // std::cout << "GAMEPAD_AXIS_LEFT_X: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisLeftX()) << std::endl;
                // std::cout << "GAMEPAD_AXIS_LEFT_Y: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisLeftY()) << std::endl;

                // Draw axis: right joystick
                // std::cout << "GAMEPAD_AXIS_RIGHT_X: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightX()) << std::endl;
                // std::cout << "GAMEPAD_AXIS_RIGHT_Y: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightY()) << std::endl;

                // Draw axis: left-right triggers
                // std::cout << "GAMEPAD_AXIS_LEFT_TRIGGER: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisLeftTrigger()) << std::endl;
                // std::cout << "GAMEPAD_AXIS_RIGHT_TRIGGER: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightTrigger()) << std::endl;
            }
        }
    }

    void SystemEvent::handleControllersGameSettings(ecs::Core &core)
    {
        (void)core;
        if (raylib::Gamepad::IsAvailable(0)) {
            return;
        }
    }

    void SystemEvent::handleControllersWin(ecs::Core &core)
    {
        (void)core;
        if (raylib::Gamepad::IsAvailable(0)) {
            return;
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
