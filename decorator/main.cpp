#include <iostream>
#include <string>
#include <functional>

template<typename T, typename... Args>
constexpr auto decorate(T(*func)(Args...)) {
	return [=](Args&&... args) {
		std::cout << "*****" << std::endl;
		T ret = func(std::forward<decltype(args)>(args)...);
		std::cout << "*****" << std::endl;
		return ret;
	};
}

int function(std::string val){
	std::cout << val<< std::endl;
	return 0;
}

constexpr auto decorated_function = decorate(function);

int main(int argc, char* argv[]) {
	auto i = decorated_function("asdf");
	std::cout << i << std::endl;

}

