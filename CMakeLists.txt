cmake_minimum_required(VERSION 3.25)
project(AuComputerScienceTest C)

set(CMAKE_C_STANDARD 11)

add_executable(AuComputerScienceTest main.c algorithm_datastructure/list/seqlist.h algorithm_datastructure/list/linkedlist.h algorithm_datastructure/list/seqlist.c algorithm_datastructure/list/linkedlist.c common.h algorithm_datastructure/stack/stack.h algorithm_datastructure/stack/stack.c algorithm_datastructure/queue/queue.c algorithm_datastructure/queue/queue.h)
