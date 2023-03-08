#include "util.h"
#include "structures.h"

std::istream& operator>>(std::istream& in, PRODUCT_TYPE& prod) {
	int type;
	if (in >> type) prod = static_cast<PRODUCT_TYPE>(type);
	return in;
}

void print_type(PRODUCT_TYPE type) {
	switch (type) {
	case KITCHEN: {
		std::cout << "Type: kitchen" << std::endl;
		break;
	}
	case BAR: {
		std::cout << "Type: bar" << std::endl;
		break;
	}
	case COMPUTER: {
		std::cout << "Type: computer" << std::endl;
		break;
	}
	case OFFICE: {
		std::cout << "Type: office" << std::endl;
		break;
	}
	default: {
		std::cout << "Type: undefined" << std::endl;
	}
	}
}

void input_product(Product& prod) {
	std::cout << "Enter name: ";
	std::cin >> prod.name;
	std::cout << "Enter type:\n";
	std::cout << "#0 = KITCHEN\n";
	std::cout << "#1 = BAR\n";
	std::cout << "#2 = OFFICE\n";
	std::cout << "#3 = COMPUTER\n";
	std::cin >> prod.type;
	std::cout << "Enter color: ";
	std::cin >> prod.color;
	std::cout << "Enter price: ";
	std::cin >> prod.price;
	std::cout << "Enter avaible amount: ";
	std::cin >> prod.available;
}