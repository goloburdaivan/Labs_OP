#include<iostream>
#include<fstream>
#include<string>
#include<errno.h>
#include<iomanip>

#pragma once

void generate_input(); // Only FileStream mode

void stream_mode(std::ifstream&, int k); // - FileStream mode

// ������������ ������� ��������� ��� � �����.
int words_count(); // - FileStream mode

// ������������ ������� ��� ��������� ������� ��������� ����� � �����.
/*
* std::string* | char** words;
* std::string* | char** unique_words;
* int* words_counter;
* int& size;
*/
void set_occurences(std::string*, std::string*, int*, int&);

// ������������ ������� ��� ������ ��� � �����
void find_words(std::ifstream&, std::string*, int*, int&, int); // - FileStream mode

// ������������ ������� ��� ������ ��������� ��� � ���� output.txt
void write_words(std::string*, int*, int, int); // - FileStream mode