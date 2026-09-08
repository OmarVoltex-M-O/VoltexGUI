#pragma once

#include "VX_Event.h"
#include "VX_HelperMacroes.h"

#include <utility>

namespace Voltex {
	template <typename T>
	class VX_Property {
	public:
		VX_Property() noexcept = default;

		VX_Property(T value) noexcept : m_value(std::move(value)) {};

		VX_Property<T>& operator=(const T& value) noexcept {
			if (value != m_value) {
				T oldValue = std::move(m_value);
				m_value = std::move(value);
				m_changed(oldValue, m_value);
			}
			return *this;
		}
		
		VX_Property<T>& operator=(T&& value) noexcept {
			if (value != m_value) {
				T oldValue = std::move(m_value);
				m_value = std::move(value);
				m_changed(oldValue, m_value);
			}
			return *this;
		}

		operator T&() noexcept { return m_value; }

		T& Get() noexcept { return m_value; }
		VX_NO_DISCARD const T& Get() const noexcept { return m_value; }

		VX_Event<const T&, const T&>& Changed() { return m_changed; }

	private:
		T m_value;
		VX_Event<const T&, const T&> m_changed;
	};
}