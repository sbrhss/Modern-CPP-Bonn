add_subdirectory(igg_image)


# Create test file
add_executable(main main.cpp)

target_link_libraries(main image strategies)
