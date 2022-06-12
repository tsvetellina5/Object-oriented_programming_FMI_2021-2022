#include "Type.h"

Type stringToType(const MyString& other)
{
    if (other == "soup")
        return Type::soup;
    else if (other == "salad")
        return Type::salad;
    else if (other == "pastry")
        return Type::pastry;
    else if (other == "stew")
        return Type::stew;
    else if (other == "steak")
        return Type::steak;
    else if (other == "sandwich")
        return Type::sandwich;
    else if (other == "dessert")
        return Type::dessert;

    return Type::unknown;
}

MyString typeToString(const Type& other)
{
    switch (other)
    {
    case Type::soup:
        return "soup";
    case Type::salad:
        return "salad";
    case Type::pastry:
        return "pastry";
    case Type::stew:
        return "stew";
    case Type::steak:
        return "steak";
    case Type::sandwitch:
        return "sandwitch";
    case Type::dessert:
        return "dessert";
    default:
        return "unknown";
    }
}
