#include "VX_ObjectPrivate.h"
#include "VX_Object.h"

Voltex::VX_Object::VX_Object(VX_ObjectPrivate& dd) : d_ptr(&dd) {}

Voltex::VX_Object::~VX_Object() {
	delete d_ptr;
	d_ptr = nullptr;
}
