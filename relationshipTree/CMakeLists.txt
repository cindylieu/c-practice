cmake_minimum_required(VERSION 3.15)
project(RelationshipTree C)

set(CMAKE_C_STANDARD 90)

add_executable(RelationshipTree main.c bst.c bst.h tree.c tree.h relationship.c relationship.h operations.c operations.h)