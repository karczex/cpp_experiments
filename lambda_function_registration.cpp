#include <exception>
#include <functional>
#include <string>
#include <iostream>

struct A
{
	std::function<void()> bar;

	void put(std::function<void()> func)
	{
		bar = func;
	}

	void call(std::string val)
	{
		bar();
	}
};

int main()
{
	A a;
	a.put([](std::string x)->int{return std::stoi(x);});
	a.call("asdf");
	return 0;
}

