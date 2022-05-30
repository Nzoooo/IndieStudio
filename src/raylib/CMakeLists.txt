set(INCROOT ${PROJECT_SOURCE_DIR}/src/raylib)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/raylib)

add_subdirectory(src)

set(SRC
    ${SRC}
    ${SRCROOT}
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
