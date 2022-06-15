#pragma once
#include "Component.h"
class Ram : public Component {
private:
	RamType ramType;
	size_t memoryCapacity;
public:
	Ram(const char*, const char*, const double, RamType, size_t);

	RamType getRamType();
	size_t getMemoryCapacity() const;

	void showComponentInfo() const override;
	ComponentType getComponentType() const override;
	void saveToFile(std::ofstream&) const override;

	Component* clone() const override;
};