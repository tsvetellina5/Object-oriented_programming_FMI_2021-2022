#pragma once
#include "ClothingItem.h"
class SportsWear : public ClothingItem {
	String sport;
public:
	SportsWear(const String& name, const double price, const size_t numAvailable);
	void setSport(const String&);
	virtual Type getType() const override;
	virtual const char* typeToStr() const override;
	virtual ClothingItem* clone() const override;
	virtual String getData() const override;
	virtual void print() const override;
};

