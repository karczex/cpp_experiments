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
	int file_write = open(path, O_CREAT | O_RDWR,
                      S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

	posix_fallocate(file_write, 0, size);
	auto *buffer = reinterpret_cast<my_data*>(mmap(NULL, size, PROT_WRITE, MAP_SHARED, file_write, 0));
	buffer->offset = 0;
	for(size_t i = 0; i< size -1; i++){
		buffer->data[i] = 'x';
		std::cout << buffer->data[i] << std::endl;
		buffer->offset++;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
