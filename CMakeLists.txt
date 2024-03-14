cmake_minimum_required(VERSION 3.25)
project(dsa)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa
        sort/basic_sort.cpp
        queue_and_stack/queue/queue.cpp
        queue_and_stack/queue/moving_average.cpp
        queue_and_stack/queue/wall_and_gate.cpp
        queue_and_stack/queue/open_the_lock.cpp
        queue_and_stack/conclusion/decoding_string.cpp
)
