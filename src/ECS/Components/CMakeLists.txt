set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)

set(SRC
    ${SRC}
    ${SRCROOT}/ComponentButton.cpp
    ${SRCROOT}/ComponentTexture.cpp
    ${SRCROOT}/ComponentMovable.cpp
    ${SRCROOT}/ComponentRectangle.cpp
    ${SRCROOT}/ComponentDrawable.cpp
    ${SRCROOT}/ComponentTransform.cpp
    ${SRCROOT}/ComponentExplodable.cpp
    ${SRCROOT}/ComponentText.cpp
    ${SRCROOT}/ComponentControllable.cpp
    ${SRCROOT}/IComponent.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
