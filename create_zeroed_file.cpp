#include <iostream>
#include <filesystem>
#include <fstream>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		exit(1);
	}

	std::filesystem::path p = argv[1];
	if (!std::filesystem::exists(p)) {
		std::ofstream(p).put(0);
		std::filesystem::resize_file(p, 1024*1024);
	}
	auto size = std::filesystem::file_size(p);
	std::cout << "file: "  << p << "size: " << size << std::endl;
}

