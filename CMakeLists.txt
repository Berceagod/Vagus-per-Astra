cmake_minimum_required(VERSION 3.26)
project(oop)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include options
include(cmake/Options.cmake)

# Fetch Raylib if not found locally
include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
        GIT_SHALLOW    TRUE
        GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(raylib)

# Define the executable
add_executable(${PROJECT_NAME}
        main.cpp
        headers/Game.h
        src/Game.cpp
        headers/Player.h
        src/Player.cpp
        headers/Inamic.h
        src/Inamic.cpp
        headers/Abilitate.h
        src/Abilitate.cpp
        headers/AdefaultGun.h
        src/AdefaultGun.cpp
        headers/ANuke.h
        src/ANuke.cpp
        headers/AElectricField.h
        src/AElectricField.cpp
        headers/ABulletBurst.h
        src/ABulletBurst.cpp
        headers/CostumExceptions.h
        src/CostumExceptions.cpp
        headers/Bullet.h
        src/Bullet.cpp
)

# Include Raylib's header directory explicitly
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_SOURCE_DIR}/src)

# Link Raylib to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Set compiler flags
include(cmake/CompilerFlags.cmake)

# Install configuration
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_BINARY_DIR}/_deps/raylib-src/src  # Path to raylib headers
)

# Copy additional files to output directory
include(cmake/CopyHelper.cmake)
copy_files(FILES tastatura.txt)
