cmake_minimum_required(VERSION 3.10)
project(HW4)

add_executable(HW4
        HW4/main.cpp
        HW4/tetris.cpp
        HW4/ui.cpp
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncursesw)

if(NCURSES_FOUND)
    include_directories(${NCURSES_INCLUDE_DIRS})
    link_directories(${NCURSES_LIBRARY_DIRS})
    target_link_libraries(HW4 PRIVATE ${NCURSES_LIBRARIES})
else()
    message(FATAL_ERROR "ncursesw not found!")
endif()

project(HW7)

add_executable(HW7
        HW7/main.cpp
        HW7/Matrix.cpp
)