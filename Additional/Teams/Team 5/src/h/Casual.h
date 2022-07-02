#pragma once
#include "ClothingItem.h"

class Casual : public ClothingItem {

public:
	Casual(const String& name, const double price, const size_t numAvailable);
	
	virtual Type getType() const override;
	virtual const char* typeToStr() const override;
	virtual ClothingItem* clone() const override;
};
