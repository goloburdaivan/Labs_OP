#define DEFAULT_INPUT_PATH "./input.txt"
#define DEFAULT_OUTPUT_PATH "./output.txt"

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

#ifndef UTIL_H
#define UTIL_H

// ������� ��� ������������� ������ ����� �����
void header(const char*);

// ������� ������ ������ ������
/*
* -mode FilePointer | FileStream
* FilePointer - ������ � ������ �� ��������� ��������� C-style.
* FileStream - ������ � ������ �� ��������� ������ C++.
*/
bool set_mode(int, char**, std::uint8_t&);

// ������������ ������� ��������� ����� input.txt


// ���������� ������� ��� �����쳿 ����, ���� ����� ���� ���� �������.
void merge(std::string*, int, int, int);
void merge(char**, int, int, int);
void merge_sort(std::string*, int, int);
void merge_sort(char**, int, int);

int words_count();

// ������������ ������� ���������� ����� � ����.
void read_file(std::ifstream&, const char*); // - FileStream mode

// ������� ��� ���������� �������� �������.
void free_mem(std::string*, std::string*, int*);

#endif // !UTIL_H
