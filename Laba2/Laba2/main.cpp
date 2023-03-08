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

	int type;
	std::cout << "Choose the type:\n";
	std::cout << "#0 = KITCHEN\n";
	std::cout << "#1 = BAR\n";
	std::cout << "#2 = OFFICE\n";
	std::cout << "#3 = COMPUTER\n";
	std::cin >> type;

	fm.generate_output(static_cast<PRODUCT_TYPE>(type));
	fm.read("output.txt");

	return 0;
}