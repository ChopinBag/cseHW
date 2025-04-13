cmake_minimum_required(VERSION 3.25)
project(MovieRatings)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        Prac02/p29/main.cpp
        Prac02/p29/movie.cpp
)
add_executable(datalab ../System_Software/test_for_datalab.c)
add_executable(tests ../../test_C.c)
add_executable(pr041
        Pr041/main.cpp
        Pr041/input.cpp
        Pr041/bmi.cpp
)
add_executable(pr038
        Pr038/main.cpp
        Pr038/tools.cpp
)
add_executable(pr042
        Pr042/main.cpp
        Pr042/command_handler.cpp
        Pr042/word_input.cpp
        Pr042/word_manager.cpp
)
add_executable(HW3
        HW3/main.cpp
        HW3/tetris.cpp
        HW3/ui.cpp
)
add_executable(HW4
        HW4/main.cpp
        HW4/tetris.cpp
        HW4/ui.cpp
)