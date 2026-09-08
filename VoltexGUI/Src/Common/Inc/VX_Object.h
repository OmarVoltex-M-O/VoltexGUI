#pragma once
#include "VX_DLLExport.h"
#include "VX_HelperMacroes.h"

namespace Voltex {
	class VX_ObjectPrivate;
	class VX_API VX_Object {
	public:
		VX_Object(VX_ObjectPrivate& dd);
		~VX_Object();
		VX_ObjectPrivate* d_ptr;

	private:
		VX_DISABLE_CLASS_COPYING(VX_Object);
	};
}