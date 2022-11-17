cmake_minimum_required(VERSION 3.12)
project(datamart CXX)
set(CMAKE_CXX_STANDARD 20)


include_directories(include)

include(third_party/userver/cmake/SetupEnvironment.cmake)
include(GNUInstallDirs)

add_subdirectory(third_party/userver)




add_library(
   CRUD OBJECT
        src/api/create.cpp
        src/api/read.cpp
        src/api/update.cpp
        src/api/delete.cpp
)


add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(CRUD PUBLIC userver-core)
target_link_libraries(CRUD PUBLIC userver-postgresql)
target_link_libraries(${PROJECT_NAME} PRIVATE CRUD)



