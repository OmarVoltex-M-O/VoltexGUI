#pragma once

#define VX_NO_DISCARD [[nodiscard]]

#define VX_DISABLE_CLASS_COPYING(Class) \
	Class(const Class&) = delete; \
	Class& operator=(const Class&) = delete;

#define VX_DISABLE_CLASS_MOVING(Class) \
	Class(Class&&) = delete; \
	Class& operator=(Class&&) = delete;

#define VX_DISABLE_CLASS_COPYING_MOVING(Class) \
	VX_DISABLE_CLASS_COPYING(Class) \
	VX_DISABLE_CLASS_MOVING(Class) \

#define VX_DECLARE_PRIVATE(Class) \
	inline Class##Private* d_func() noexcept { return reinterpret_cast<Class##Private*>(d_ptr); } \
	inline VX_NO_DISCARD const Class##Private* d_func() const noexcept { return reinterpret_cast<const Class##Private*>(d_ptr); } \
	friend Class##Private;

#define VX_DECLARE_PUBLIC(Class) \
	inline Class* q_func() noexcept { return reinterpret_cast<Class*>(q_ptr); } \
	inline VX_NO_DISCARD const Class* q_func() const noexcept { return reinterpret_cast<const Class*>(q_ptr); } \
	friend Class;

#define VX_D(Class) Class##Private* d = d_func(); 
#define VX_Q(Class) Class* q = q_func(); 
