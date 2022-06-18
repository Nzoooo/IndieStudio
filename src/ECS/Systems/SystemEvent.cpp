/*
** EPITECH PROJECT, 2022
** SystemEvent
** File description:
** SystemEvent
*/

#include "SystemEvent.hpp"
#include "raylib/include/Gamepad.hpp"

namespace ecs
{
    static bool isClicking(raylib::Rectangle *rectangle)
    {
        raylib::Mouse mouseIndex;
        if ((mouseIndex.GetX() >= rectangle->x) && (mouseIndex.GetY() >= rectangle->y) && (mouseIndex.GetX() < rectangle->x + rectangle->width)
            && (mouseIndex.GetY() < rectangle->height + rectangle->y)) {
            return (true);
        }
        return (false);
    }

    bool SystemEvent::_isControllerAssign(ecs::Core &index, int gamepadNumber)
    {
        for (auto *it : index.getEntities()) {
            if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() == gamepadNumber)
                return (true);
        }
        return (false);
    }

    void SystemEvent::_assignController(ecs::Core &index, int gamepadNumber)
    {
        for (auto *it : index.getEntities()) {
            if (it->has<ComponentControllable>() && it->get<ComponentControllable>()->getGamepadId() == -1) {
                it->get<ComponentControllable>()->setGamepadId(gamepadNumber);
                return;
            }
        }
        return;
    }

    void SystemEvent::_reassignControllers(ecs::Core &index, int gamepadNumber)
    {
        (void)index;
        (void)gamepadNumber;
    }

    void SystemEvent::_detectNbControllers()
    {
        // if (raylib::Gamepad::IsAvailable(0)) { // && !IsControllerAssign(0)
        //     // assign to player
        //     raylib::Gamepad::gamepadNumber++;
        if (!raylib::Gamepad::IsAvailable(0)) { // && IsControllerAssign(0)
            // reassign all controllers to players
            raylib::Gamepad::gamepadNumber--;
        }
        // if (raylib::Gamepad::IsAvailable(1)) { // && !IsControllerAssign(1)
        //     // assign to player
        //     raylib::Gamepad::gamepadNumber++;
        if (!raylib::Gamepad::IsAvailable(1)) { // && IsControllerAssign(1)
            // reassign all controllers to players
            raylib::Gamepad::gamepadNumber--;
        }
        // if (raylib::Gamepad::IsAvailable(2)) { // && !IsControllerAssign(2)
        //     // assign to player
        //     raylib::Gamepad::gamepadNumber++;
        if (!raylib::Gamepad::IsAvailable(2)) { // && IsControllerAssign(2)
            // reassign all controllers to players
            raylib::Gamepad::gamepadNumber--;
        }
        // if (raylib::Gamepad::IsAvailable(3)) { // && !IsControllerAssign(3)
        //     // assign to player
        //     raylib::Gamepad::gamepadNumber++;
        if (!raylib::Gamepad::IsAvailable(3)) { // && IsControllerAssign(3)
            // reassign all controllers to players
            raylib::Gamepad::gamepadNumber--;
        }
    }

    void SystemEvent::_resetStateButtons(ecs::Core &index, int idButton)
    {
        for (auto *it : index.getEntities()) {
            if (it->has<ComponentButton>() && it->get<ComponentButton>()->getIdButton() != idButton)
                it->get<ComponentButton>()->setState(false);
        }
    }

    void SystemEvent::_handleButtonsMoveUpDown(ecs::Core &index, int upOrDown)
    {
        static int tmpIdButton = 0;
        int idMax = 0;
        bool isId = false;

        for (auto *it : index.getEntities()) {
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
        for (auto *it : index.getEntities()) {
            if (it->has<ComponentButton>() && it->get<ComponentButton>()->getIdButton() == tmpIdButton + upOrDown) {
                it->get<ComponentButton>()->setState(true);
                tmpIdButton = it->get<ComponentButton>()->getIdButton();
                _resetStateButtons(index, it->get<ComponentButton>()->getIdButton());
                break;
            }
        }
    }

    void SystemEvent::_handleClickOnButtons(ecs::Core &index)
    {
        for (auto *it : index.getEntities()) {
            if (it->has<ComponentButton>() && it->get<ComponentButton>()->getState()) {
                // it->get<ComponentButton>()->setTexture("//texturePath");
                break;
            }
        }
    }

    void SystemEvent::handleControllersMenu(ecs::Core &index)
    {
        int i = 0;
        raylib::Mouse mouseIndex;

        if (raylib::Gamepad::IsAvailable(0)) {
            if (raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonRightFaceDown())) {
                _handleClickOnButtons(index);
            }
            if (raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == 1 || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceDown())) {
                _handleButtonsMoveUpDown(index, 1);
            }
            if (raylib::Gamepad::GetAxisMovement(0, raylib::Gamepad::GamepadAxisLeftY()) == -1 || raylib::Gamepad::IsButtonReleased(0, raylib::Gamepad::GamepadButtonLeftFaceUp())) {
                _handleButtonsMoveUpDown(index, -1);
            }
        }
        // else {
        for (size_t j = 0; i < index.getNbButtons(); j++) {
            if (index.getEntity(j)->has<ComponentButton>()) {
                index.getEntity(j)->get<ComponentButton>()->setState(false);
                raylib::Rectangle *buttonTmp = new raylib::Rectangle(index.getEntity(j)->get<ComponentButton>()->getPos().x, index.getEntity(j)->get<ComponentButton>()->getPos().y,
                    index.getEntity(j)->get<ComponentButton>()->getRectangleActive()->width, index.getEntity(j)->get<ComponentButton>()->getRectangleActive()->height);
                if (isClicking(buttonTmp) == true && i == 0) {
                    index.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        index.setScene(ecs::Scenes::Game);
                } else if (isClicking(buttonTmp) == true && i == 1) {
                    index.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        index.setScene(ecs::Scenes::Close);
                } else if (isClicking(buttonTmp) == true && i == 2) {
                    index.getEntity(j)->get<ComponentButton>()->setState(true);
                    if (mouseIndex.IsButtonPressed(mouseIndex.MouseButtonLeft()))
                        index.setScene(ecs::Scenes::Close);
                }
                i++;
            }
        }
        // }
    }

    void SystemEvent::handleControllersConnectPlayers(ecs::Core &index)
    {
        for (int i = 0; i <= raylib::Gamepad::gamepadNumber; i++) {
            if (raylib::Gamepad::IsAvailable(i)) {
                if (raylib::Gamepad::IsButtonReleased(i, raylib::Gamepad::GamepadButtonRightFaceDown())) {
                    // create a player
                    _assignController(index, i);
                }
            }
        }
    }

    void SystemEvent::handleControllersGame(ecs::Core &index)
    {
        raylib::Gamepad::gamepadNumber = 0;
        for (int i = 0; i <= raylib::Gamepad::gamepadNumber; i++) {
            //  && _isControllerAssign(index, i)
            if (raylib::Gamepad::IsAvailable(i)) {
                // Draw buttons: xbox home
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddle()))
                    std::cout << "home" << std::endl;

                // Draw buttons: basic
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddleRight()))
                    std::cout << "start" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddleLeft())) {}
                // std::cout << "select" << std::endl;
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
                // if ()
                for (auto *it : index.getEntities()) {
                    // && it->get<ComponentControllable>()->getGamepadId() == i
                    if (it->has<ComponentControllable>()) {
                        raylib::Vector3 pos(it->get<ComponentCube>()->getPos());
                        raylib::Vector3 size(it->get<ComponentCube>()->getSize());
                        if (raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightY()) < 0) {
                            std::cout << "manette haut" << std::endl;
                            if (!it->get<ComponentCollider>()->getVector(ComponentCollider::NORTH)) {
                                std::cout << "je move" << std::endl;
                                std::cout << "le bool north = " << it->get<ComponentCollider>()->getVector(ComponentCollider::NORTH) << std::endl;
                                std::cout << "le bool east = " << it->get<ComponentCollider>()->getVector(ComponentCollider::EAST) << std::endl;
                                std::cout << "le bool south = " << it->get<ComponentCollider>()->getVector(ComponentCollider::SOUTH) << std::endl;
                                std::cout << "le bool west = " << it->get<ComponentCollider>()->getVector(ComponentCollider::WEST) << std::endl;
                                std::cout << "je suis en " << it->get<ComponentCube>()->_posTmp.x << "x et " << it->get<ComponentCube>()->_posTmp.z << "z" << std::endl;
                                it->get<ComponentCube>()->_pos.z -= 0.02f;
                                // it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::LEFT);
                            }
                            // it->get<ComponentCollider>()->setCollision(raylib::BoundingBox(
                            //     raylib::Vector3(pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2), raylib::Vector3(pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2)));
                        } else if (raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightX()) > 0) {
                            it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::RIGHT);
                            // it->get<ComponentCollider>()->setCollision(raylib::BoundingBox(
                            //     raylib::Vector3(pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2), raylib::Vector3(pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2)));
                        } else if (raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightY()) < 0) {
                            it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::UP);
                            // it->get<ComponentCollider>()->setCollision(raylib::BoundingBox(
                            //     raylib::Vector3(pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2), raylib::Vector3(pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2)));
                        } else if (raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightY()) > 0) {
                            it->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::DOWN);
                            // it->get<ComponentCollider>()->setCollision(raylib::BoundingBox(
                            //     raylib::Vector3(pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2), raylib::Vector3(pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2)));
                        }
                    }
                }
            }
        }
    }

    void SystemEvent::handleControllersGameSettings(ecs::Core &index)
    {
        (void)index;
        if (raylib::Gamepad::IsAvailable(0)) {
            return;
        }
    }

    void SystemEvent::handleControllersWin(ecs::Core &index)
    {
        (void)index;
        if (raylib::Gamepad::IsAvailable(0)) {
            return;
        }
    }

    void SystemEvent::update(ecs::Core &index)
    {
        raylib::Gamepad::gamepadNumber = 3;
        _detectNbControllers();
        if (index.getScene() == ecs::Scenes::Menu)
            handleControllersMenu(index);
        if (index.getScene() == ecs::Scenes::ConnectPlayers)
            handleControllersConnectPlayers(index);
        if (index.getScene() == ecs::Scenes::Game)
            handleControllersGame(index);
        if (index.getScene() == ecs::Scenes::GameSettings)
            handleControllersGameSettings(index);
        if (index.getScene() == ecs::Scenes::Win)
            handleControllersWin(index);
    }
} // namespace ecs
