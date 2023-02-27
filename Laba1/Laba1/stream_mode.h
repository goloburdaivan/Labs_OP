#include<iostream>
#include<fstream>
#include<string>
#include<errno.h>
#include<iomanip>

#pragma once

void generate_input(); // Only FileStream mode

void stream_mode(std::ifstream&, int k); // - FileStream mode

// Перевантажені функції підрахунку слів в тексті.
int words_count(); // - FileStream mode

// Перевантажені функції для підрахунку кількості повторень слова в тексті.
/*
* std::string* | char** words;
* std::string* | char** unique_words;
* int* words_counter;
* int& size;
*/
void set_occurences(std::string*, std::string*, int*, int&);

// Перевантажені функції для пошуку слів в тексті
void find_words(std::ifstream&, std::string*, int*, int&, int); // - FileStream mode

// Перевантажені функції для запису знайдених слів у файл output.txt
void write_words(std::string*, int*, int, int); // - FileStream mode