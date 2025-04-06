cmake_minimum_required(VERSION 3.25)
project(MovieRatings)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        Prac02/p29/main.cpp
        Prac02/p29/movie.cpp
)
add_executable(datalab ../System_Software/test_for_datalab.c)
add_executable(tests ../../test_C.c)
