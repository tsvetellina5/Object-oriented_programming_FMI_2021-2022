#pragma once
#include "Component.h"
class Gpu : public Component {
private:
	size_t videoMemory;
public:
	Gpu(const char*, const char*, const double, size_t);

	size_t getVideoMemory() const;

	void showComponentInfo() const override;
	ComponentType getComponentType() const override;
	void saveToFile(std::ofstream&) const override;

	Component* clone() const override;
};