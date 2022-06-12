cmake_minimum_required(VERSION 3.21)
project(Team_13)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Team_13
        ColdMeal.cpp
        ColdMeal.h
        HotMeal.cpp
        HotMeal.h
        Pair.hpp
        Recipe.cpp
        Recipe.h
        String.cpp
        String.h
        Vector.hpp
        RecipeBook.cpp
        RecipeBook.h
        Type.cpp
        Type.h)
