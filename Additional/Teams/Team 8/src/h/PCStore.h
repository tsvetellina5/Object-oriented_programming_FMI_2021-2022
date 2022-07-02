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
	bool checkBalance(double) const;

	const double getMoney() const;
	void subtractFunds(double);
	void addFunds(double);

	void printComponentInfos() const;

	void addMotherboard(Motherboard);
	void addCpu(const Cpu);
	void addGpu(const Gpu);
	void addRam(const Ram);

	bool sellComponent(size_t);

	bool removeFromIndex(size_t);

	bool buildComputer();
	bool checkCompatibilityCpu(Motherboard&, Cpu&) const;
	bool checkCompatibilityRam(Motherboard&, Ram&) const;

	void writeToFile() const;

private:
	void copy(const PCStore&);
	void free();
	void resize();
};