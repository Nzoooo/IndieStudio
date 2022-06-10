set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)

set(SRC
    ${SRC}
    ${SRCROOT}/ComponentMovable.cpp
    ${SRCROOT}/ComponentDrawable.cpp
    ${SRCROOT}/ComponentTransform.cpp
    ${SRCROOT}/ComponentExplodable.cpp
    ${SRCROOT}/ComponentBombs.cpp
    ${SRCROOT}/IComponent.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
