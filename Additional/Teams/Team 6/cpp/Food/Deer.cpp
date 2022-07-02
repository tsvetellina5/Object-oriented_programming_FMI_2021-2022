#include "Deer.h"

Deer::Deer() : Food(40) {
    type = Type::MEAT;
}

const String* Deer::convertTypeToString() const
{
    return new String("Deer");
}

Food* Deer::clone() const
{
    return new Deer(*this);
}
