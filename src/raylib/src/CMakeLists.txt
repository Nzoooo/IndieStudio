set(INCROOT ${PROJECT_SOURCE_DIR}/src/raylib/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/raylib/src)

set(SRC
    ${SRC}
    ${SRCROOT}/Window.cpp
    ${SRCROOT}/Model.cpp
    ${SRCROOT}/ModelAnimation.cpp
    ${SRCROOT}/BoundingBox.cpp
    ${SRCROOT}/Rectangle.cpp
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}/Window.hpp
    ${INCROOT}/Model.hpp
    ${INCROOT}/ModelAnimation.hpp
    ${INCROOT}/Texture.hpp
    ${INCROOT}/Vector2.hpp
    ${INCROOT}/Vector3.hpp
    ${INCROOT}/BoundingBox.hpp
    PARENT_SCOPE
)
