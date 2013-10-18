/*
 * Compartment.c
 *
 *  Created on: Oct 17, 2013
 *      Author: pedro
 */

#include <assert.h>

#include "Compartment.h"
#include "Compartment.r"

/*
 *	Compartment
 */

static void* Compartment_ctor(void* _self, va_list * app)
{
	struct Compartment * self = super_ctor(Compartment, _self, app);

	self->my_id 		= va_arg(*app, unsigned int);
	self->mech_count 	= va_arg(*app, unsigned int);
	self->mechanisms 	= va_arg(*app, void**);

	return self;
}

static void Compartment_step_simulate_fxn (void* _self,
		  	  	  	  	  	  	  	  	       void** network,
		  	  	  	  	  	  	  	  	       const double dt,
		  	  	  	  	  	  	  	  	       const double global_time,
		  	  	  	  	  	  	  	  	       const unsigned int curr_step)
{
	const struct Compartment * self = _self;

	printf("My id is %u and I have %u mechanisms\n", self->my_id, self->mech_count);
}

void step_simulate_fxn (void* _self,
						  void** network,
						  const double dt,
						  const double global_time,
						  const unsigned int curr_step)
{
	const struct CompartmentClass * class = classOf(_self);

	assert(class->step_simulate_fxn);
	class->step_simulate_fxn(_self,
							network,
							dt,
							global_time,
							curr_step);
}

void super_step_simulate_fxn (const void * _class,
							  	 void* _self,
							  	 void** network,
							  	 const double dt,
							  	 const double global_time,
							  	 const unsigned int curr_step)
{
	const struct CompartmentClass * superclass = super(_class);

	assert(_self && superclass->step_simulate_fxn);
	superclass->step_simulate_fxn(_self,
								 network,
								 dt,
								 global_time,
								 curr_step);
}

/*
 *	CompartmentClass
 */

static void* CompartmentClass_ctor(void* _self, va_list * app)
{
	struct CompartmentClass * self = super_ctor(CompartmentClass, _self, app);
	voidf selector;

	while ((selector = va_arg(*app, voidf)))
	{
		voidf method = va_arg(*app, voidf);

		if (selector == (voidf) step_simulate_fxn)
		{
			*(voidf *) &self->step_simulate_fxn = method;
		}
	}

	return self;
}

/*
 *	initialization
 */

const void* CompartmentClass, *Compartment;

void initCompartment(void)
{
	if (!CompartmentClass)
	{
		CompartmentClass = new(Class,
							   "CompartmentClass",
							   Class,
							   sizeof(struct CompartmentClass),
							   ctor,
							   CompartmentClass_ctor,
							   0);
	}

	if (!Compartment)
	{
		Compartment = new(CompartmentClass,
					"Compartment",
					Object,
					sizeof(struct Compartment),
					ctor,
					Compartment_ctor,
					step_simulate_fxn,
					Compartment_step_simulate_fxn,
					0);
	}
}

