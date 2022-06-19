set(INCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ECS/Components)

set(SRC
    ${SRC}
    ${SRCROOT}/ComponentBombs.cpp
    ${SRCROOT}/ComponentButton.cpp
    ${SRCROOT}/ComponentCollider.cpp
    ${SRCROOT}/ComponentControllable.cpp
    ${SRCROOT}/ComponentCube.cpp
    ${SRCROOT}/ComponentDrawable.cpp
    ${SRCROOT}/ComponentExplodable.cpp
    ${SRCROOT}/ComponentExplosion.cpp
    ${SRCROOT}/ComponentFireBlast.cpp
    ${SRCROOT}/ComponentKills.cpp
    ${SRCROOT}/ComponentMesh.cpp
    ${SRCROOT}/ComponentModel.cpp
    ${SRCROOT}/ComponentMovable.cpp
    ${SRCROOT}/ComponentRectangle.cpp
    ${SRCROOT}/ComponentText.cpp
    ${SRCROOT}/ComponentTexture.cpp
    ${SRCROOT}/ComponentTransform.cpp
    ${SRCROOT}/ComponentTransparency.cpp
    ${SRCROOT}/ComponentVent.cpp
    ${SRCROOT}/IComponent.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
