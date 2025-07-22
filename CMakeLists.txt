cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(ChromaBackend VERSION 1.0.0 LANGUAGES CXX)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

include(cmake/CPM.cmake)
CPMAddPackage("gh:fmtlib/fmt#11.2.0")
CPMAddPackage("gh:gabime/spdlog#v1.15.3")
CPMAddPackage("gh:rpclib/rpclib#v2.3.0")
CPMAddPackage("gh:nlohmann/json#v3.12.0")

set(HTTPLIB_REQUIRE_ZSTD OFF)
set(HTTPLIB_USE_ZSTD_IF_AVAILABLE OFF)
CPMAddPackage("gh:yhirose/cpp-httplib#v0.23.1")

target_link_libraries(${PROJECT_NAME} PRIVATE
    fmt
    spdlog::spdlog
    rpc
    nlohmann_json::nlohmann_json
    httplib
)
target_include_directories(${PROJECT_NAME} PRIVATE 
    "include/"
)