#include <iostream>

#include <regex>
#include <string>
#include <vector>

#define FOO  1
#define BAR  2


int parse_string(std::string seq) {

	std::map<std::string, int> tokens = {{"FOO", FOO}, {"BAR", BAR}};
	int result = 0;
	std::regex rgx("\\w+");

	for( std::sregex_iterator it(seq.begin(), seq.end(), rgx), it_end; it != it_end; ++it){
		auto token = tokens.find((*it)[0]);
		if (token != tokens.end()) {
			result |= token->second;
		}
	}

	return result;

}

int main(int argc, char* argv[]) {
	int i = parse_string(argv[1]);
	std::cout << i << std::endl;
}

