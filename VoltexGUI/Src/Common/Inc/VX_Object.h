#pragma once

namespace Voltex {
	class VX_ObjectPrivate;
	class VX_Object {
	public:
		VX_Object(VX_ObjectPrivate& dd);
		~VX_Object();
		VX_ObjectPrivate* d_ptr;
	};
}