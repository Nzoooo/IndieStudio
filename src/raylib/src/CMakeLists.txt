set(INCROOT ${PROJECT_SOURCE_DIR}/src/raylib/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/raylib/src)

set(SRC
    ${SRC}
    ${SRCROOT}/BoundingBox.cpp
    ${SRCROOT}/Model.cpp
    ${SRCROOT}/ModelAnimation.cpp
    ${SRCROOT}/Texture.cpp
    ${SRCROOT}/Window.cpp
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
