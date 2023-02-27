#define _CRT_SECURE_NO_WARNINGS
#include "util.h"
#include "fpointer_mode.h"
#include "stream_mode.h"


int main(int argc, char** argv) {

	FILE* file = NULL;
	std::ifstream in;
	std::uint8_t mode;	
	int k;

	std::cout << "Enter number of occurences: ";
	std::cin >> k;

	int counter = 0;

	if (!set_mode(argc, argv, mode)) {
		std::cout << "[ERROR] Wrong mode! See -mode help for more information." << std::endl;
		return 0;
	}

	switch (mode) {
		case 0: {
			std::cout << "FilePointer mode activated..." << std::endl;
			filep_mode(file, k);

			header("input.txt: ");
			read_file(file, DEFAULT_INPUT_PATH);
			header("output.txt: ");
			read_file(file, DEFAULT_OUTPUT_PATH);

			break;
		}
		case 1: {
			std::cout << "FileStream mode activated..." << std::endl;
			stream_mode(in, k);

			header("input.txt: ");
			read_file(in, DEFAULT_INPUT_PATH);
			header("output.txt: ");
			read_file(in, DEFAULT_OUTPUT_PATH);
			break;
		}
		case 2: {
			std::cout << "[HELP] Usage: a.exe -mode [FilePointer | FileStream]" << std::endl;
			break;
		}
	}

	return 0;
}