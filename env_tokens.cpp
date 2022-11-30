#include <iostream>
#include <regex>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
	auto env = std::getenv("ENV_PASS");
	std::string senv(env ? env : "");
	std::regex rgx("(\\w+)(\\||$)");
	for( std::sregex_iterator it(senv.begin(), senv.end(), rgx), it_end; it != it_end; ++it){
		std::cout << (*it)[1].str() << std::endl;
	}
}

