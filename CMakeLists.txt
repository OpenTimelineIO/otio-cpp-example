cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0076 NEW)

project(otio-cpp-example VERSION 1.0)

add_executable(otio-cpp-example example.cpp)
set_property(TARGET otio-cpp-example PROPERTY CXX_STANDARD 14)

set(OTIO_SHARED_LIBS OFF)
add_subdirectory("libs/OpenTimelineIO")
include_directories(
  ${PROJECT_SOURCE_DIR}/libs/OpenTimelineIO/src
  ${PROJECT_SOURCE_DIR}/libs/OpenTimelineIO/src/deps
  ${PROJECT_SOURCE_DIR}/libs/OpenTimelineIO/src/deps/optional-lite/include
)

target_link_libraries(otio-cpp-example OTIO::opentimelineio)
