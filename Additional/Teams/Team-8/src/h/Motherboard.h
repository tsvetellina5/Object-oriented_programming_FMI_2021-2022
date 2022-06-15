#pragma once
#include "Component.h"
class Motherboard : public Component {
private:
	Socket socket;
	RamType ramType;
public:
	Motherboard(const char*, const char*, const double, Socket, RamType);

	Socket getSocket() const;
	RamType getRamType() const;

	void showComponentInfo() const override;
	ComponentType getComponentType() const override;
	void saveToFile(std::ofstream&) const override;

	Component* clone() const override;
};