set(INCROOT ${PROJECT_SOURCE_DIR}/src/core/information)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/core/information)

set(SRC
    ${SRC} ${SRCROOT}/info.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
