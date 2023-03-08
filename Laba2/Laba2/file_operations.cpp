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

bool FileManager::read(const char* filename) const {
	std::ifstream in(filename, std::ios::binary);
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

bool FileManager::generate_output(PRODUCT_TYPE type) const {
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
	Product* products = new Product[size];
	in.seekg(0, std::ios::beg);

	for (size_t i = 0; i < size; i++) {
		in.read((char*)&products[i], sizeof(Product));
	}
	in.close();

	std::ofstream out(_output_path, std::ios::app | std::ios::binary);
	if (!out.is_open()) {
		strerror_s(error_buf, errno);
		std::cout << "[Error]" << error_buf << std::endl;
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (products[i].type == type) {
			out.write((char*)&products[i], sizeof(Product));
		}
	}

	out.close();

	delete[] products;

	return true;
}