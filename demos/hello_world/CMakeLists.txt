get_filename_component(CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# build
set(TARGET ${CURRENT_FOLDER})
add_executable(${TARGET} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)