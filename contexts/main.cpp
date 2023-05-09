#include <iostream>
#include <functional>


class classWithContext{
private:
	int context = 0;
public:
	classWithContext(int num) : context(num){}

	void operator()(int val){
		std::cout << val + context << std::endl;
	}

};

void runner(std::function<void(int)> func_with_context){
	constexpr int n = 42;
	func_with_context(n);
}


int main(int argc, char* argv[]) {

	// Passing context in class instance
	auto f = classWithContext{12};
	runner(f);
	
	// Passing context captured by value(copy) inside lamba function. May be
	// passed by reference if needed
	int context_from_local_scope = 21;

	runner([=](int val) {
		std::cout << val + context_from_local_scope << std::endl;
		});
}

