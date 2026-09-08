#pragma once

#include "VX_Event.h"

#include <utility>

namespace Voltex {
	template <typename T>
	class VX_Property {
	public:
		VX_Property() noexcept = default;

		VX_Property(T value) noexcept : m_value(value) {};

		void operator=(const T& value) noexcept {
			if (value != m_value) {
				T oldValue = std::move(m_value);
				m_value = std::move(value);
				m_changed(oldValue, m_value);
			}
		}

		operator T&(){ return m_value; }

		T& Get() { return m_value; }
		const T& Get() const { return m_value; }

		VX_Event<const T&, const T&>& Changed() { return m_changed; }

	private:
		T m_value;
		VX_Event<const T&, const T&> m_changed;
	};
}