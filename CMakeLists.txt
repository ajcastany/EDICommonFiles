cmake_minimum_required(VERSION 3.25)
project(CommonFormatFile VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Library
add_library(CommonFormatFile
  src/CommonFormatFile.cpp
  src/FileHeader.cpp
  src/Validator.cpp)


target_include_directories(CommonFormatFile PRIVATE src)

target_include_directories(CommonFormatFile PUBLIC include)

# Link libraries
# target_link_libraries(CommonFormatFile PUBLIC)

# unit tests
enable_testing()
add_subdirectory(test)
