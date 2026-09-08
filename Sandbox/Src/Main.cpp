#include "VX_Property.h"

#include <print>

class Test {
public:
	Voltex::VX_Property<int> Age = 100;
	Voltex::VX_UI64 id;
	Test() {
		id = Age.Changed() += { this, &Test::OnAgeChanged };
		Age.Changed() += [this](const int& oldValue, const int& newValue) {
			std::print("----Called from lambada Old value is {} New value is {}\n", oldValue, newValue);
		};
	}
	void OnAgeChanged(const int& oldValue, const int& newValue) {
		std::print("----Called from a regular function Old value is {} New value is {}\n", oldValue, newValue);
	}
};

int main() {
	Test test;
	test.Age = 100;
	test.Age = 10000;
	test.Age = 1000;
}
