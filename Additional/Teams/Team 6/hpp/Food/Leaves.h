#pragma once
#include "Food.h"

class Leaves : public Food {
public:
	Leaves();
	const String* convertTypeToString() const override;
	Food* clone() const override;
};