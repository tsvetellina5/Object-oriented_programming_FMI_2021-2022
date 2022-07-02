#include "Pig.h"

Pig::Pig() : Food(55) {
    type = Type::MEAT;
}

const String* Pig::convertTypeToString() const
{
    return new String("Pig");
}

Food* Pig::clone() const
{
    return new Pig(*this);
}
