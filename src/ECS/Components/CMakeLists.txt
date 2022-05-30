set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)

set(SRC
    ${SRC}
    ${SRCROOT}/ComponentMovable.cpp
    ${SRCROOT}/ComponentDrawable.cpp
    ${SRCROOT}/ComponentTransform.cpp
    ${SRCROOT}/ComponentCollider.cpp
    ${SRCROOT}/ComponentPickable.cpp
    ${SRCROOT}/ComponentDroppable.cpp
    ${SRCROOT}/ComponentExplodable.cpp
    ${SRCROOT}/ComponentKillable.cpp
    ${SRCROOT}/ComponentClickable.cpp
    ${SRCROOT}/IComponent.cpp
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
