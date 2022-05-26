set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)

set(SRC
    ${SRC}
    ${SRCROOT}/ComponentMovable.cpp
    ${SRCROOT}/ComponentTransform.cpp
    ${SRCROOT}/ComponentKillable.cpp
    ${SRCROOT}/IComponent.cpp
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
