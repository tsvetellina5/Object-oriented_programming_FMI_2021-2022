#include "Fish.h"

Fish::Fish() : Food(30) {
    type = Type::SEAFOOD;
}

const String* Fish::convertTypeToString() const
{
    return new String("Fish");
}

Food* Fish::clone() const
{
    return new Fish(*this);
}
