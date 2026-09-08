#pragma once

#ifdef VX_BUILD_DLL
	#ifdef VX_OS_WINDOWS
		#ifdef VX_EXPORT_DLL
			#define VX_API __declspec(dllexport)
		#else
			#define VX_API __declspec(dllimport)
		#endif	// VX_EXPORT_DLL
	#else
		#define VX_API
	#endif // VX_OS_WINDOWS
#else
	#define VX_API
#endif // VX_BUILD_DLL