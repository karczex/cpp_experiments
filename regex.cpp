#include <iostream>
#include <regex>

int main(int argc, char* argv[]) {

    std::string s(argv[1]);
    std::regex rgx("(\\d+):(\\d+):(\\d+)");
    std::smatch matches;

    if(std::regex_search(s, matches, rgx)) {
        std::cout << "Match found\n";

        for (size_t i = 0; i < matches.size(); ++i) {
            std::cout << i << ": '" << matches[i].str() << "'\n";
        }
    } else {
        std::cout << "Match not found\n";
    }

}

