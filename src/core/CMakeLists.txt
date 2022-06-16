set(INCROOT ${PROJECT_SOURCE_DIR}/src/core)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/core)

add_subdirectory(information)

set(SRC
    ${SRC} ${SRCROOT}/core.cpp ${SRCROOT}/mainMenu.cpp ${SRCROOT}/gameMenu.cpp
    ${SRCROOT}/initMap.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
