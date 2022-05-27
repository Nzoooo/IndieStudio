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
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}/Window.hpp
    ${INCROOT}/Model.hpp
    ${INCROOT}/ModelAnimation.hpp
    ${INCROOT}/BoundingBox.hpp
    ${SRCROOT}/Rectangle.hpp
    ${SRCROOT}/Color.hpp
    ${INCROOT}/Texture.hpp
    ${INCROOT}/Vector2.hpp
    ${INCROOT}/Vector3.hpp
    ${SRCROOT}/Camera2D.hpp
    ${SRCROOT}/Camera3D.hpp
    PARENT_SCOPE
)
