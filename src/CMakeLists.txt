set(INCROOT ${PROJECT_SOURCE_DIR}/src)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC)

add_subdirectory(raylib)
add_subdirectory(core)
add_subdirectory(ECS)
add_subdirectory(map)
add_subdirectory(save)
add_subdirectory(load)

set(INCDIRS ${INCROOT})

source_group("" FILES ${SRC})

set(LIB_NAME libbomberman)
set(TARGET_NAME bomberman)

add_library(${LIB_NAME} ${SRC})

target_include_directories(${LIB_NAME} PRIVATE ${INCDIRS})
target_include_directories(${LIB_NAME} PUBLIC ${INCROOT})

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE ${LIB_NAME})

# ---------------------------------RAYLIB---------------------------------- ##
find_package(raylib REQUIRED)
target_link_libraries(${TARGET_NAME} PRIVATE raylib)
# ------------------------------------------------------------------------- ##

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if(APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework IOKit")
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
  target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

add_custom_command(
  TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}>
          ${PROJECT_SOURCE_DIR})
