#include "Squid.h"

Squid::Squid() : Food(50) {
    type = Type::SEAFOOD;
}

const String* Squid::convertTypeToString() const
{
    return new String("Squid");
}

Food* Squid::clone() const
{
    return new Squid(*this);
}
