#pragma once
#include "Food.h"

class Fish : public Food {
public:
	Fish();
	const String* convertTypeToString() const override;
	Food* clone() const override;
};