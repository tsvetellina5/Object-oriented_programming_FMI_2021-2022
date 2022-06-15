#pragma once
#include "Component.h"
class Motherboard : public Component {
private:
	Socket socket;
	RamType ramType;
public:
	Motherboard(const char*, const char*, const double, const Socket, const RamType);

	Socket getSocket() const;
	RamType getRamType() const;

	void showComponentInfo() const override;
	void saveToFile(std::ofstream&) const override;

	Component* clone() const override;
};