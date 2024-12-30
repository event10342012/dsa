cmake_minimum_required(VERSION 3.25)
project(dsa)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa
        queue_and_stack/conclusion/decoding_string.cpp
        queue_and_stack/conclusion/matrix.cpp
        heap/heap.cpp
        heap/meeting_rooms_2.cpp
        heap/furthestBuilding.cpp
)
