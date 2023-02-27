#define DEFAULT_INPUT_PATH "./input.txt"
#define DEFAULT_OUTPUT_PATH "./output.txt"

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

#ifndef UTIL_H
#define UTIL_H

// Функція для форматованого виводу назви файлу
void header(const char*);

// Функція вибору режиму роботи
/*
* -mode FilePointer | FileStream
* FilePointer - робота з файлом за допомогою покажчика C-style.
* FileStream - робота з файлом за допомогою потоків C++.
*/
bool set_mode(int, char**, std::uint8_t&);

// Перевантажені функції генерації файлу input.txt


// Сортування злиттям для економії часу, адже текст може бути великим.
void merge(std::string*, int, int, int);
void merge(char**, int, int, int);
void merge_sort(std::string*, int, int);
void merge_sort(char**, int, int);

int words_count();

// Перевантажені функції зчитування даних з фалу.
void read_file(std::ifstream&, const char*); // - FileStream mode

// Функції для вивільнення виділених ресурсів.
void free_mem(std::string*, std::string*, int*);

#endif // !UTIL_H
