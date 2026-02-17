cmake_minimum_required(VERSION 3.11)
project(MagPulse)

set(CMAKE_CXX_STANDARD 17)

# Point to SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-3.0.2/lib/cmake/SFML")
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)

# Build the app
add_executable(MagPulse src/main.cpp)
target_link_libraries(MagPulse PRIVATE SFML::Graphics SFML::Window SFML::System)

# Copy the CORRECT 3.0.2 DLLs
if(WIN32)
    add_custom_command(TARGET MagPulse POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/SFML-3.0.2/bin/sfml-graphics-d-3.dll"
        "${CMAKE_CURRENT_SOURCE_DIR}/SFML-3.0.2/bin/sfml-window-d-3.dll"
        "${CMAKE_CURRENT_SOURCE_DIR}/SFML-3.0.2/bin/sfml-system-d-3.dll"
        $<TARGET_FILE_DIR:MagPulse>
    )
endif()
