#pragma once
#include "PCStore.h"
#define BUFFER_LINE 256
PCStore readComponents();

Motherboard readMotherboard(const char*);
Cpu readCpu(const char*);
Gpu readGpu(const char*);
Ram readRam(const char*);

double readDoubleAtIndex(const char*, int, int);
char* readStringAtIndex(const char*, int, int);

int getIndexOfSpace(const char*, int);

bool checkStartsWith(const char*, const char*);

bool checkFileExists(const char*);

char* substr(const char*, size_t);