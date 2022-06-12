#pragma once
#include "Food.h"

class Deer : public Food {
public:
	Deer();
	const String* convertTypeToString() const override;
	Food* clone() const override;
};