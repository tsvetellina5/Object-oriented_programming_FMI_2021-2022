#pragma once
#include "Food.h"

class Squid : public Food {
public:
	Squid();
	const String* convertTypeToString() const override;
	Food* clone() const override;
};