#pragma once
#include"String.h"

class ClothingItem {
protected:
	enum class Gender {
		MAN,
		WOMAN,
		UNISEX
	} gender;
	enum class Size {
		XS,
		S,
		M,
		L,
		XL,
		XXL,
		UNKNOWN
	}size;

	enum class Type {
		Casual,
		Sportswear,
		Couture,
		UNKNOWN
	} type;
	String name;
	double price;
	size_t numAvailable;

public:
	ClothingItem();
	ClothingItem(const String&, const double, const size_t);

	virtual ~ClothingItem() = default;

	void setName(const String&);
	void setPrice(const double);
	void setNumAvailable(const size_t);
	void setGender(const char&);
	void setSize(const String&);

	virtual Type getType() const;
	Gender getGender() const;
	Size getSize() const;

	const String& getName() const;
	double getPrice() const;
	size_t getNumAvailable() const;

	virtual const char* typeToStr() const;
	virtual const char* sizeToStr() const;
	virtual const char* genderToStr() const;

	virtual ClothingItem* clone() const = 0;
	virtual String getData() const;
	virtual void print() const;
};
