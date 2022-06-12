cmake_minimum_required(VERSION 3.21)
project(Team_13)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Team_13
        src/cpp/ColdMeal.cpp
        src/hpp/ColdMeal.h
        src/cpp/HotMeal.cpp
        src/hpp/HotMeal.h
        src/hpp/Pair.hpp
        src/cpp/Recipe.cpp
        src/hpp/Recipe.h
        src/cpp/String.cpp
        src/hpp/String.h
        src/hpp/Vector.hpp
        src/cpp/RecipeBook.cpp
        src/hpp/RecipeBook.h
        src/cpp/Type.cpp
        src/hpp/Type.h)
