project(project-euler-study)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

add_executable(main src/main.cpp lib/PEBasic.h lib/Combinatorics.h lib/Modint.h lib/Bigint.h lib/Primes.h lib/UnionFind.h)