#pragma once

#include "VX_Types.h"

#include <functional>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string.h>

namespace Voltex {
	struct VX_EventToken {
		VX_UI64 id;
	};

	template <typename... Args>
	class VX_EventHandler {
	public:
		VX_EventHandler() noexcept = default;
		template <typename T>
		VX_EventHandler(T* inst, void(T::* method)(Args... args)) noexcept : 
			m_instance(inst),
			m_methodSize(sizeof(method)),
			m_isMemberFunction(true) {
			std::memcpy(m_methodBytes, &method, m_methodSize);
			m_callable = [inst, method](const Args&... args) {
				(inst->*method)(args...);
			};
		};
		VX_EventHandler(std::function<void(Args...)> fun) noexcept : 
			m_callable(fun),
			m_isMemberFunction(false) {};

		[[nodiscard]]void operator()(const Args&... args) const noexcept {
			if (m_callable) {
				m_callable(args...);
			}
		}

		bool operator==(const VX_EventHandler other) {
			if (!m_isMemberFunction) {
				return false;
			}
			return m_methodSize== other.m_methodSize && 
				m_instance == other.m_instance && 
				std::memcmp(m_methodBytes, other.m_methodBytes, m_methodSize) == 0;
		}

	private:
		unsigned char m_methodBytes[32] = {};
		VX_UI64 m_methodSize;
		void* m_instance;
		std::function<void(Args...)> m_callable;
		bool m_isMemberFunction;
	};

	template <typename... Args>
	class VX_Event {
	public:
		using VX_Handler = VX_EventHandler<Args...>;

		VX_EventToken operator+=(VX_Handler handler) noexcept {
			m_nextId++;
			m_handlers[m_nextId] = std::move(handler);
			return { m_nextId };
		}
		
		void operator-=(VX_Handler handler) noexcept {
			for (const auto& [id, hand] : m_handlers) {
				if (hand == handler) {
					m_handlersToUnsubscribe.push_back(id);
				}
			}
		}
		
		void operator-=(const VX_UI64& id) noexcept {
			if (auto it = m_handlers.find(id); it == m_handlers.end()) return;
			m_handlersToUnsubscribe.push_back(id);
		}

		void operator()(const Args&... args) noexcept {
			for (const auto& [id, handler] : m_handlers) {
				handler(args...);
			}
			if (m_handlersToUnsubscribe.size() > 0) {
				for (auto& i : m_handlersToUnsubscribe) {
					m_handlers.erase(i);
				}
				m_handlersToUnsubscribe.clear();
			}
		}

	private:
		VX_UI64 m_nextId = 0;
		std::unordered_map<VX_UI64, VX_Handler> m_handlers;
		std::vector<VX_UI64> m_handlersToUnsubscribe;
	};
}