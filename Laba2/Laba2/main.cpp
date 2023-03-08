#include<iostream>
#include "structures.h"
#include "file_operations.h"
#include "util.h"

int main() {

	FileManager fm;

	Product product;
	char flag;
	std::cout << "[INFO] Type exit if you want to break input." << std::endl;
	while (true) {
		std::cout << std::endl;
		input_product(product);
		std::cout << "Continue? [Y/N] ";
		fm.write(product);
		std::cin >> flag;
		if (flag != 'Y' && flag != 'y') break;
	}

	fm.read();

	return 0;
}