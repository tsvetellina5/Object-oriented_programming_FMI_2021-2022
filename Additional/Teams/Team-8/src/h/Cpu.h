#pragma once
#include "Component.h"
class Cpu : public Component {
private:
	Socket socket;
	size_t cores;
public:
	Cpu(const char*, const char*, const double, Socket, size_t);

	Socket getSocket() const;
	size_t getCores() const;

	void showComponentInfo() const override;
	ComponentType getComponentType() const override;
	void saveToFile(std::ofstream&) const override;

	Component* clone() const override;
};