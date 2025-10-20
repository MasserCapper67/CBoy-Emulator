file(GLOB sources CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/lib/*.c")
file(GLOB headers CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.h")

# Create static library
add_library(emu STATIC ${sources} ${headers})

# Include directories
target_include_directories(emu
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# SDL2 setup
if (WIN32)
    target_include_directories(emu PUBLIC
        "${PROJECT_SOURCE_DIR}/../windows_deps/sdl2/include"
        "${PROJECT_SOURCE_DIR}/../windows_deps/sdl2_ttf/include"
    )
else()
    # Use SDL2 variables found by find_package(SDL2 REQUIRED)
    target_include_directories(emu PUBLIC ${SDL2_INCLUDE_DIRS})
endif()

# Link libraries (keyword style only)
target_link_libraries(emu
    PUBLIC
        ${SDL2_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)

