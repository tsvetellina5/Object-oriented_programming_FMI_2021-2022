#include "Leaves.h"

Leaves::Leaves() : Food(25) {
    type = Type::PLANTS;
}

const String* Leaves::convertTypeToString() const
{
    return new String("Leaves");
}

Food* Leaves::clone() const
{
    return new Leaves(*this);
}

