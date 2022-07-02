#pragma once
#include "Component.h"
class Cpu : public Component {
private:
	Socket socket;
	size_t cores;
public:
	Cpu(const char*, const char*, const double, const Socket, const size_t);

	Socket getSocket() const;
	size_t getCores() const;

	void showComponentInfo() const override;
	void saveToFile(std::ofstream&) const override;

	Component* clone() const override;
};