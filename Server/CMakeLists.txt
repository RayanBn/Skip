cmake_minimum_required(VERSION 3.20)
project("Skip-Server")

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCE ${SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    ${SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    asio
)
