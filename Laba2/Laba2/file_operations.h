#pragma once
#include "structures.h"
#include<fstream>
#include<iostream>

class FileManager {
private:
	std::string _input_path;
	std::string _output_path;
public:
	FileManager(): _input_path("input.txt"), _output_path("output.txt") {}
	FileManager(std::string input_path, std::string output_path) :
		_input_path(input_path),
		_output_path(output_path) {}

	bool write(const Product& product) const;
	bool read() const;
	bool read(const char* filename) const;
	bool generate_output(PRODUCT_TYPE type) const;
};