# unit tests pacakge
find_package(GTest REQUIRED)

set(TEST_SOURCES
    test_file_header.cpp
    test_centre_header.cpp
    test_centre_trailer.cpp
    test_file_trailer.cpp)

# Loop in test sources:
foreach(TEST_SOURCE ${TEST_SOURCES})
  get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SOURCE})
  target_include_directories(${TEST_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src     # Include the 'src' directory
    ${CMAKE_CURRENT_SOURCE_DIR}/../include # Include the public headers
  )
  target_link_libraries(${TEST_NAME} PRIVATE CommonFormatFile GTest::GTest GTest::Main)
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
