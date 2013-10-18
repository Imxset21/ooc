/*
 * Compartment.h
 *
 *  Created on: Oct 17, 2013
 *      Author: pedro
 */

#ifndef COMPARTMENT_H_
#define COMPARTMENT_H_

//	Import Object.h since this is an object
#include "Object.h"

//	Object definition

extern const void* Compartment;		//	Declare for new() operator

void step_simulate_fxn (void* _self,
						  void** network,
						  const double dt,
						  const double global_time,
						  const unsigned int curr_step);

//	Class definition

extern const void* CompartmentClass;	//	Declare for class definition

void initCompartment(void);

#endif /* COMPARTMENT_H_ */
