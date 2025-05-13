#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
 
	std::string data;
	size_t i =0;
	while(std::cin >> data){
		std::cout << "chunk "  << i << " : " << data << std::endl;
		i++;
	}
}

