cmake_minimum_required(VERSION 3.5)

project(05_state)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(SFML REQUIRED
    sfml-all
    )
set(SRCS
    src/main.cpp
    src/Application.cpp
    src/State.cpp
    src/StateStack.cpp
    src/TitleState.cpp
    src/MenuState.cpp
    src/Logger.cpp
    )
add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src
    ${SFML_INCLUDE_DIRS})

file(COPY res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})