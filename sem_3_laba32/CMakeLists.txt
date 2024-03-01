cmake_minimum_required(VERSION 3.20)
project(sem_3_laba32)

#set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES sem_3_laba32 main.cpp  ListSequence.h Sequence.h LinkedList.h DynamicArray.h ArraySequence.h Graph.h UndirectedGraph.h ISorter.h Board.h GUI.h MMA.h) 
add_executable(${SOURCE_FILES})
include_directories(/usr/local/include)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(sem_3_laba32 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)



