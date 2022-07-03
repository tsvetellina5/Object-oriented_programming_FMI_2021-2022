#pragma once

const size_t MAX_NAME_SIZE = 22;
struct Student
{
	//gender should be BEFORE fn, in order for the struct to be 28 bytes.
	char name[MAX_NAME_SIZE + 1];
	bool isMale;
	size_t fn;
};