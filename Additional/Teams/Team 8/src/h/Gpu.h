#pragma once
#include "Component.h"
class Gpu : public Component {
private:
	size_t videoMemory;
public:
	Gpu(const char*, const char*, const double, const size_t);

	size_t getVideoMemory() const;

	void showComponentInfo() const override;
	void saveToFile(std::ofstream&) const override;

	Component* clone() const override;
};