#include <iostream>
#include <functional>
#include <concepts>

#include <vector>

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

//This one doesn't use std::function. It is type safe and would not compile if F
//doen't implement operator()
template<typename F>
void runner_without_std_func(F func_with_context) {
	constexpr int n = 44;
	func_with_context(n);
}

//Similar to previous one but with ptr so may be used with contexts stored in
//some global container
template<typename F>
void runner_without_std_func_ptr(F *func_with_context) {
	constexpr int n = 46;
	(*func_with_context)(n);
}


int main(int argc, char* argv[]) {

	// Passing context in class instance
	auto f = classWithContext{12};
	runner(f);

	std::cout << std::endl;

	runner_without_std_func(f);

	std::cout << std::endl;

	// Passing context captured by value(copy) inside lamba function. May be
	// passed by reference if needed
	int context_from_local_scope = 21;


	runner([&](int val) {
		std::cout << val + context_from_local_scope << std::endl;
		});

	std::cout << std::endl;
	
	//create contexts
	std::vector<classWithContext> global_contexts_container;
	constexpr int elements = 25;
	for(int i=0; i< elements; i++){
		global_contexts_container.emplace_back(i);
	}
	//let's iterate over contexts;
	for(auto it=global_contexts_container.begin(); it != global_contexts_container.end(); it++ ){
		//trick to get raw pointer from iterator
		classWithContext *context_ptr = &(*it);
		runner_without_std_func_ptr(context_ptr);
	}
}

