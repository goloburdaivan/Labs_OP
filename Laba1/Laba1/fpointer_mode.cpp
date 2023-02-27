#define _CRT_SECURE_NO_WARNINGS
#include "fpointer_mode.h"
#include "util.h"

void set_occurences(char** words,
	char** unique_words, int* words_counter, int& unique_size) {

	int size = words_count();

	for (int i = 0; i < size; i++) {
		bool found = false;
		for (int j = 0; j < unique_size; j++) {
			if (strcmp(words[i], unique_words[j]) == 0) {
				words_counter[j]++;
				found = true;
				break;
			}
		}

		if (!found) {
			strcpy(unique_words[unique_size], words[i]);
			words_counter[unique_size] = 1;
			unique_size++;
		}
	}
}


void generate_input(FILE* file) {

	char error_buf[256];

	file = fopen(DEFAULT_INPUT_PATH, "a");
	if (file == NULL) {
		strerror_s(error_buf, errno);
		std::cout << "[ERROR]" << error_buf << std::endl;
		return;
	}

	std::cout << "[INFO] Enter the text: ";
	std::cin.ignore();

	char* text = new char[256];
	while (true) {
		std::cin.getline(text, 255);
		if (text[0] == '\n' || text[0] == '\0') break;
		fprintf(file, "%s\n", text);
	}

	delete[] text;
	fclose(file);
}

void filep_mode(FILE* file, int k) {
	generate_input(file);
	file = fopen(DEFAULT_INPUT_PATH, "r");

	char** unique_words = nullptr;
	int* words_counter = nullptr;
	int size = 0;

	find_words(file, unique_words, words_counter, size, k);
	fclose(file);
}

void find_words(FILE* file, char** unique_words, int* words_counter, int& unique_size, int k) {

	char error_buf[256];
	if (file == NULL) {
		strerror_s(error_buf, errno);
		std::cout << "[ERROR]" << error_buf << std::endl;
		return;
	}

	int index = 0, w_index = 0, size = words_count();
	char character, word[256];
	char** words = new char* [size];
	for (int i = 0; i < size; i++) words[i] = new char[256];

	unique_words = new char* [size];
	for (int i = 0; i < size; i++) unique_words[i] = new char[256];

	words_counter = new int[size];


	while ((character = fgetc(file)) != EOF) {
		if (character != ',' && character != ' ' && character != '.' && character != '\n') {
			word[index++] = character;
			word[index] = '\0';
		}
		else {
			if (word[0] != '\0') {
				strcpy(words[w_index++], word);
				word[0] = 0;
				index = 0;
			}
		}
	}

	set_occurences(words, unique_words, words_counter, unique_size);
	write_words(file, unique_words, words_counter, size, k);

	fclose(file);
}

void write_words(FILE* file, char** unique_words, int* words_counter, int size, int k) {

	char** words = new char* [size];
	for (int i = 0; i < size; i++) words[i] = new char[256];
	char error_buf[256];
	int index = 0;

	file = fopen(DEFAULT_OUTPUT_PATH, "w");
	if (file == NULL) {
		strerror_s(error_buf, errno);
		std::cout << "[ERROR]" << error_buf << std::endl;
		return;
	}


	for (int i = 0; i < size; i++) {
		if (words_counter[i] > k) {
			strcpy(words[i], unique_words[i]);
		}
	}

	merge_sort(words, 0, size - 1);


	for (int i = 0; i < size; i++) {
		if (words[i][0] != '\0') {
			if (isascii(words[i][0])) fputs(words[i], file), fputs("\n", file);
		}
	}


	free_mem(words, unique_words, words_counter, size);

	fclose(file);
}

void read_file(FILE* file, const char* filename) {
	char error_buf[256];
	char buffer;

	file = fopen(filename, "r");

	if (file == NULL) {
		strerror_s(error_buf, errno);
		std::cout << "[ERROR] " << error_buf;
		return;
	}

	while ((buffer = fgetc(file)) != EOF) {
		std::cout << buffer;
	}

	fclose(file);
}

void free_mem(char** words, char** unique_words, int* words_counter, int size) {
	delete[] unique_words;
	delete[] words;
	delete[] words_counter;
}