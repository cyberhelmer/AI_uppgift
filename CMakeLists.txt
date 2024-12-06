cmake_minimum_required(VERSION 3.10)
project(AI_app)

set(CMAKE_CXX_STANDARD 17)

add_executable(AI_app
        main.cpp
        contact.cpp
        database.cpp
)

# Link SQLite3 library
find_package(SQLite3 REQUIRED)
target_link_libraries(AI_app PRIVATE SQLite::SQLite3)
