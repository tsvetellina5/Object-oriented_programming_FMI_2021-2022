#pragma once

#include "Container.h"
#include "vector.h"
#include "Driver.h"

class Transport{

    public:
        static void menu();
        static void print();
        static void add();
        static void remove();
        static void travel();
    private:
        static Vector<Driver> drivers;
        static Container vehicles;
};