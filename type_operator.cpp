#include <iostream>

struct fake_number {
	size_t value = 0;

	operator size_t()
	{
		value++;
		return value;
	}
};

void func(size_t v){
	std::cout << v << std::endl;
}

int main(int argc, char* argv[]) {
	fake_number n;
	func(n);
	func(n);
}

