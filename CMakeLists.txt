cmake_minimum_required(VERSION 3.25)
project(dsa)

set(CMAKE_CXX_STANDARD 17)

add_executable(dsa
        sort/basic_sort.cpp
        queue_and_stack/queue.cpp
        queue_and_stack/moving_average.cpp
        queue_and_stack/wall_and_gate.cpp
        queue_and_stack/open_the_lock.cpp)
