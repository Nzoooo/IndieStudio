set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Systems)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Systems)

set(SRC
    ${SRC}
    ${SRCROOT}/ISystem.cpp
    ${SRCROOT}/SystemRender2D.cpp
    ${SRCROOT}/SystemRender3D.cpp
    ${SRCROOT}/SystemEvent.cpp
    ${SRCROOT}/SystemExplosion.cpp
    ${SRCROOT}/SystemCollision.cpp
    ${SRCROOT}/SystemIA.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
