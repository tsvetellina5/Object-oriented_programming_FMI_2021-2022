#pragma once
#include "Component.h"
#include "Motherboard.h"
#include "Cpu.h"
#include "Gpu.h"
#include "Ram.h"
class PCStore
{
private:
	Component** components;
	size_t countComponents;
	size_t capacityComponents;
	double money;
public:
	PCStore();
	PCStore(const PCStore&);
	PCStore& operator=(const PCStore&);
	~PCStore();

	void setMoney(double);
	bool checkBalance(double);

	const double getMoney() const;
	void subtractFunds(double);
	void addFunds(double);

	void printComponentInfos() const;

	void addMotherboard(Motherboard);
	void addCpu(Cpu);
	void addGpu(Gpu);
	void addRam(Ram);

	void sellComponent(size_t);

	void removeFromIndex(size_t);

	void buildComputer();
	bool checkCompatibilityCpu(Motherboard&, Cpu&);
	bool checkCompatibilityRam(Motherboard&, Ram&);

	void writeToFile() const;

private:
	void copy(const PCStore&);
	void free();
	void resize();
};