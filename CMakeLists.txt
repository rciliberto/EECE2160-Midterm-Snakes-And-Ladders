# CMake version
cmake_minimum_required(VERSION 2.8.7)

# Project
project(Midterm)

# Flags
set(CMAKE_CXX_STANDARD 98)

# Include
include_directories(lib/DE1SoCfpga/include lib/DE1SoCfpga/src)

add_subdirectory(lib/DE1SoCfpga)

# Executable
add_executable(Midterm src/main.cpp  src/SnakesAndLadders/Model/SimpleSnakesAndLadders/SimpleSnakesAndLadders.cpp src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/Board.cpp src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/ComPlayer.cpp src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/SnakeLadder.cpp  src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Board/BoardBuilder.cpp src/SnakesAndLadders/Model/SimpleSnakesAndLadders/Player/Player.cpp src/SnakesAndLadders/View/SnakesAndLaddersCLIView.cpp src/SnakesAndLadders/Controller/SnakesAndLaddersCLIController.cpp src/MusicPlayer/MusicPlayer.cpp)

# Link Library
target_link_libraries(Midterm DE1SoCfpga)


