#define _CRT_SECURE_NO_WARNINGS
#include "util.h"

/*
* Тут знаходяться реалізації функцій з заголовочного файлу util.h
* Для більш детальної інформації про ці функції - дивіться util.h
*/

void header(const char* text) {
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl;
	std::cout << std::setfill(' ') << std::setw(30) << text << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl;
}

void merge(std::string* array, int l, int m, int r) {
	int left_size = m - l + 1;
	int right_size = r - m;
	std::string* L = new std::string[left_size];
	std::string* R = new std::string[right_size];

	for (int i = 0; i < left_size; i++) {
		L[i] = array[l + i];
	}

	for (int i = 0; i < right_size; i++) {
		R[i] = array[m + i + 1];
	}

	int i = 0, j = 0, k = l;
	while (i < left_size && j < right_size) {
		if (L[i].length() <= R[j].length()) {
			array[k] = L[i];
			i++;
			k++;
		}
		else {
			array[k] = R[j];
			j++;
			k++;
		}
	}

	while (i < left_size) {
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < right_size) {
		array[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void merge(char** array, int l, int m, int r) {
	int left_size = m - l + 1;
	int right_size = r - m;
	char** L = new char*[left_size];
	for (int i = 0; i < left_size; i++) L[i] = new char[256];
	char** R = new char*[right_size];
	for (int i = 0; i < right_size; i++) R[i] = new char[256];

	for (int i = 0; i < left_size; i++) {
		strcpy(L[i], array[l + i]);
	}

	for (int i = 0; i < right_size; i++) {
		strcpy(R[i], array[m + i + 1]);
	}

	int i = 0, j = 0, k = l;
	while (i < left_size && j < right_size) {
		if (strlen(L[i]) <= strlen(R[j])) {
			strcpy(array[k], L[i]);
			i++;
			k++;
		}
		else {
			strcpy(array[k], R[j]);
			j++;
			k++;
		}
	}

	while (i < left_size) {
		strcpy(array[k], L[i]);
		i++;
		k++;
	}

	while (j < right_size) {
		strcpy(array[k], R[j]);
		j++;
		k++;
	}
}

void merge_sort(std::string* array, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		merge_sort(array, l, m);
		merge_sort(array, m + 1, r);
		merge(array, l, m, r);
	}
}

void merge_sort(char** array, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		merge_sort(array, l, m);
		merge_sort(array, m + 1, r);
		merge(array, l, m, r);
	}
}

bool set_mode(int argc, char** argv, std::uint8_t& mode) {
	if (argc != 3) return false;

	std::string _mode_flag(argv[1]);
	std::string _mode(argv[2]);
	bool flag = true;

	if (_mode_flag != "-mode") return false;

	if (_mode == "FilePointer") {
		mode = 0;
	}
	else if (_mode == "FileStream") {
		mode = 1;
	}
	else if (_mode == "help") {
		mode = 2;
	}
	else {
		flag = false;
	}

	return flag;
}

int words_count() {
	std::ifstream in(DEFAULT_INPUT_PATH);
	std::string temp;
	int size = 0;

	while (in >> temp) {
		size++;
	}

	in.close();

	return size;
}