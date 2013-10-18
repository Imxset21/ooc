#include <stdlib.h>
#include <stdio.h>
#include "Compartment.h"

int main (int argc, char ** argv)
{
	void * c;

	initCompartment();

	c = new(Compartment, 0, 0, NULL);

	step_simulate_fxn(c, NULL, 0.0, 0.0, 0);

	delete(c);

	return 0;
}
