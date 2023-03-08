#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include "util.h"

enum PRODUCT_TYPE {
	KITCHEN,
	BAR,
	OFFICE,
	COMPUTER
};

struct Product {
	std::string name;
	PRODUCT_TYPE type;
	std::string color;
	int price;
	int available;

	void print() {
		std::cout << std::setfill('=') << std::setw(50) << " = " << std::endl;
		std::cout << std::setfill(' ') << std::setw(30) << "Product" << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << " = " << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Type: " << type << std::endl;
		print_type(type);
		std::cout << "Price: " << price << std::endl;
		std::cout << "Available: " << available << std::endl;
	}
};