#include "stream_mode.h"
#include "util.h"

void generate_input() {

	std::ofstream out;
	std::string text;
	char error_buf[256];

	out.open(DEFAULT_INPUT_PATH, std::ios::app);
	if (!out.is_open()) {
		strerror_s(error_buf, errno);
		std::cout << "[ERROR]" << error_buf << std::endl;
		return;
	}

	std::cout << "[INFO] Enter the text: ";
	std::cin.ignore();
	while (true) {
		std::getline(std::cin, text);
		if (text[0] == '\0') break;
		out << text << std::endl;
	}

	out.close();
}

void stream_mode(std::ifstream& in, int k) {
	generate_input();
	in.open(DEFAULT_INPUT_PATH, std::ios::app);

	std::string* unique_words = nullptr;
	int* words_counter = nullptr;
	int size = 0;

	find_words(in, unique_words, words_counter, size, k);

	in.close();
}

void set_occurences(std::string* words,
	std::string* unique_words, int* words_counter, int& unique_size) {

	int size = words_count();

	for (int i = 0; i < size; i++) {
		bool found = false;
		for (int j = 0; j < unique_size; j++) {
			if (words[i] == unique_words[j]) {
				words_counter[j]++;
				found = true;
				break;
			}
		}

		if (!found) {
			unique_words[unique_size] = words[i];
			words_counter[unique_size] = 1;
			unique_size++;
		}
	}
}

void find_words(std::ifstream& in, std::string* unique_words,
	int* words_counter, int& unique_size, int k) {

	char error_buf[256];
	int size = words_count(),
		index = 0;

	std::string* words = new std::string[size];
	unique_words = new std::string[size];
	words_counter = new int[size];

	if (!in.is_open()) {
		strerror_s(error_buf, errno);
		std::cout << "[ERROR]" << error_buf << std::endl;
		return;
	}

	std::string sentence;

	while (in >> sentence) {
		size_t coma_pos = sentence.find(',');
		size_t dot_pos = sentence.find('.');
		std::string replaced;

		if (coma_pos != std::string::npos) {
			replaced = sentence.replace(coma_pos, 1, "");
			words[index++] = replaced;
		}
		else if (dot_pos != std::string::npos) {
			replaced = sentence.replace(dot_pos, 1, "");
			words[index++] = replaced;
		}
		else {
			words[index++] = sentence;
		}
	}

	set_occurences(words, unique_words, words_counter, unique_size);
	write_words(unique_words, words_counter, size, k);
}

void write_words(std::string* unique_words, int* words_counter, int size, int k) {

	std::string* words = new std::string[size];
	std::ofstream out(DEFAULT_OUTPUT_PATH);

	int index = 0;
	char error_buf[256];
	if (!out.is_open()) {
		strerror_s(error_buf, errno);
		std::cout << error_buf << std::endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		if (words_counter[i] > k) {
			words[index++] = unique_words[i];
		}
	}

	merge_sort(words, 0, size - 1);

	for (int i = 0; i < size; i++) {

		if (words[i][0] != '\0') out << words[i] << "\n";
	}


	free_mem(words, unique_words, words_counter);
	out.close();
}



void read_file(std::ifstream& in, const char* filename) {
	char error_buf[256];
	std::string line;

	in.open(filename);

	if (!in.is_open()) {
		strerror_s(error_buf, errno);
		std::cout << "[ERROR] " << error_buf;
		return;
	}

	while (!in.eof()) {
		std::getline(in, line);
		std::cout << line << std::endl;
	}

	in.close();
}


void free_mem(std::string* words, std::string* unique_words, int* words_counter) {
	delete[] unique_words;
	delete[] words;
	delete[] words_counter;
}