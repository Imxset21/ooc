/*
 * Compartment.r
 *
 *  Created on: Oct 17, 2013
 *      Author: pedro
 */

#ifndef	COMPARTMENT_R
#define	COMPARTMENT_R

//	Include Object representation
#include "Object.r"

struct Compartment
{
	const struct Object _;			//! Point : Object
	unsigned int my_id;				//!	ID (or index) of this compartment
	unsigned int mech_count;		//! Number of mechanisms ending at this compartment
	void** mechanisms;				//!	Channels 'ending' at this compartment
};

void super_step_simulate_fxn (const void * _class,
							  	 void* _self,
							  	 void** network,
							  	 const double dt,
							  	 const double global_time,
							  	 const unsigned int curr_step);

struct CompartmentClass
{
	const struct Class _;			/* CompartmentClass : Class */
	void (*step_simulate_fxn) (void* self,
							   void** network,
							   const double dt,
							   const double global_time,
							   const unsigned int curr_step);
};

#endif
