set(INCROOT ${PROJECT_SOURCE_DIR}/src/raylib/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/raylib/src)

set(SRC
    ${SRC}
    ${SRCROOT}/Window.cpp
    ${SRCROOT}/Model.cpp
    ${SRCROOT}/ModelAnimation.cpp
    ${SRCROOT}/BoundingBox.cpp
    ${SRCROOT}/Rectangle.cpp
    ${SRCROOT}/Color.cpp
    ${SRCROOT}/Texture.cpp
    ${SRCROOT}/Vector2.cpp
    ${SRCROOT}/Vector3.cpp
    ${SRCROOT}/Camera2D.cpp
    ${SRCROOT}/Camera3D.cpp
    ${SRCROOT}/Font.cpp
    ${SRCROOT}/Mouse.cpp
    ${SRCROOT}/Gamepad.cpp
    ${SRCROOT}/Mesh.cpp
    ${SRCROOT}/Image.cpp
    ${SRCROOT}/Sound.cpp
    ${SRCROOT}/Music.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}/Window.hpp
    ${INCROOT}/Model.hpp
    ${INCROOT}/ModelAnimation.hpp
    ${INCROOT}/BoundingBox.hpp
    ${INCROOT}/Rectangle.hpp
    ${INCROOT}/Color.hpp
    ${INCROOT}/Texture.hpp
    ${INCROOT}/Vector2.hpp
    ${INCROOT}/Vector3.hpp
    ${INCROOT}/Camera2D.hpp
    ${INCROOT}/Camera3D.hpp
    ${INCROOT}/Font.hpp
    ${INCROOT}/Mouse.hpp
    ${INCROOT}/Gamepad.hpp
    ${INCROOT}/Mesh.hpp
    ${INCROOT}/Image.hpp
    ${INCROOT}/Sound.hpp
    ${INCROOT}/Music.hpp
    PARENT_SCOPE)
