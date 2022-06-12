#pragma once
#include "Food.h"

class Pig : public Food {
public:
	Pig();
	const String* convertTypeToString() const override;
	Food* clone() const override;
};