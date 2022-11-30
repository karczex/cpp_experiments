#include <fcntl.h>
#include <sys/mman.h>

#include <iostream>

#include <thread>
#include <chrono>


#include "data_structure.h"

int main(int argc, char *argv[])
{
	auto path = argv[1];
	size_t size = 4096;
	int file_read = open(path, O_RDONLY);

	auto *buffer = reinterpret_cast<my_data*>(mmap(NULL, size, PROT_READ, MAP_SHARED, file_read, 0));

	size_t last_offset = 0;
	while(true) {
		size_t current_offset = buffer->offset;
		for( size_t i = last_offset; i < current_offset; i++) {
			std::cout << buffer->data[i] << std::endl;
		}
		last_offset = current_offset;
		if( last_offset == buffer->offset) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}
