#include <iostream>
#include <string>
#include <stdio.h>

int main(int arg, char* argv[]) {

	std::string meta_descriptor = "";
	for (size_t i=0; i <3; i++){
		meta_descriptor.append("%d");
	}
	meta_descriptor += "\n";
	printf(meta_descriptor.c_str(), 1 ,2 ,3);

}

