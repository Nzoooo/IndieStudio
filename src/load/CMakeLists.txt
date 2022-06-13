set(INCROOT ${PROJECT_SOURCE_DIR}/src/load)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/load)

set(SRC
    ${SRC} ${SRCROOT}/load.cpp ${SRCROOT}/loadComponent.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
