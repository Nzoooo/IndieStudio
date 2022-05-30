set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Systems)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Systems)

set(SRC
    ${SRC}
    ${SRCROOT}/ISystem.cpp
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
