cmake_minimum_required(VERSION 3.5)

project(hello_sfml)

find_package(PkgConfig)
pkg_check_modules(SFML REQUIRED
    sfml-all
    )
set(SRCS
    main.cpp
    )
add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC
    #${CMAKE_CURRENT_LIST_DIR}/inc
    ${SFML_INCLUDE_DIRS})