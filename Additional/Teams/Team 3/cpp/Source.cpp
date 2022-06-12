#include "Fauna.h"
#include "Flora.h"
#include "Fungi.h"
#include "RedBook.h"

#include "VectorC.hpp"
#include "StringC.h"

int main()
{
	VectorC<StringC> hab;
	hab.push("Africa");
	hab.push("South Asia");

	Flora f("orchid", 4, hab, "least concern");
	Fungi fun("guba", 1, hab, "extinct", false);
	
	RedBook b;
	b.addOrganism(f);
	b.addOrganism(fun);

	b.printAll();

	return 0;
}