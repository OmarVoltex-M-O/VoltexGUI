#include "VX_Property.h"

#include <print>

class Test {
public:
	Voltex::VX_Property<int> Age = 100;
	Voltex::VX_EventToken token;
	Test() {
		token = Age.Changed() += { this, &Test::OnAgeChanged };
	}
	void OnAgeChanged(const int& oldValue, const int& newValue) {
		Age.Changed() -= token.id;
		std::print("Old value is {} New value is {}\n", oldValue, newValue);
	}
};

int main() {
	Test test;
	test.Age = 100;
	test.Age = 10000;
	test.Age = 1000;
}
