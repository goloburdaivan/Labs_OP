#include "file_operations.h"

bool FileManager::write(const Product& prod) const {
	std::ofstream out(_input_path, std::ios::app | std::ios::binary);
	char error_buf[255];
	if (!out.is_open()) {
		strerror_s(error_buf, errno);
		std::cout << "[Error]" << error_buf << std::endl;
		return false;
	}

	out.write((char*)&prod, sizeof(Product));
	out.close();

	return true;
}

bool FileManager::read() const {
	std::ifstream in(_input_path, std::ios::binary);
	char error_buf[255];
	if (!in.is_open()) {
		strerror_s(error_buf, errno);
		std::cout << "[Error]" << error_buf << std::endl;
		return false;
	}

	// Отримати розмір файлу в байтах.
	in.seekg(0, std::ios::end);
	size_t file_size = in.tellg();
	size_t size = file_size / sizeof(Product);

	// Переводимо вказівник на початок.
	in.seekg(0, std::ios::beg);

	Product* products = new Product[size];
	for (size_t i = 0; i < size; i++) {
		in.read((char*)&products[i], sizeof(Product));
		products[i].print();

	}
	in.close();

	delete[] products;

	return true;
}