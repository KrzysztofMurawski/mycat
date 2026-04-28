cmake_minimum_required(VERSION 3.31)

project(mycat C)

add_executable(${PROJECT_NAME} main.c)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin)