set(INCROOT ${PROJECT_SOURCE_DIR}/src/core)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/core)

add_subdirectory(information)

set(SRC
    ${SRC}
    ${SRCROOT}/core.cpp
    ${SRCROOT}/mainMenu.cpp
    ${SRCROOT}/initMap.cpp
    ${SRCROOT}/pauseMenu.cpp
    ${SRCROOT}/connectPlayers
    ${SRCROOT}/gameSettings
    ${SRCROOT}/winMenu.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
