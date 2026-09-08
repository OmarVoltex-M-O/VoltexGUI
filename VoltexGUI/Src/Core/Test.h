#pragma once

#include "VX_DLLExport.h"

#include <print>

namespace Voltex {
	class VX_API Test {
	public:
		Test() {
			std::print("Hello");
		}
	};
}