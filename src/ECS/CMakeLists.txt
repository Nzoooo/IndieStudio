set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS)

add_subdirectory(Components)
add_subdirectory(Entities)
add_subdirectory(Systems)

set(SRC
    ${SRC} ${SRCROOT}/ecs.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
