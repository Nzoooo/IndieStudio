set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Entities)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Entities)

set(SRC
    ${SRC}
    ${SRCROOT}/IEntity.cpp
    ${SRCROOT}/PlayerEntity.cpp
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
