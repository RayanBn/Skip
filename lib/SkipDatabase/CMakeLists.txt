cmake_minimum_required(VERSION 3.20)

project("SkipDatabase")

file(GLOB_RECURSE SOURCE src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    src
)

find_package(libmysqlclient REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC
    libmysqlclient::libmysqlclient
)