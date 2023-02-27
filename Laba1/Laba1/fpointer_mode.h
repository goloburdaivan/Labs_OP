#include<iostream>
#include<fstream>
#include<string>
#include<errno.h>
#include<iomanip>

#pragma once

void generate_input(FILE*); // Only FilePointer mode
void filep_mode(FILE*, int); // - FilePointer mode
void set_occurences(char**, char**, int*, int&);
void find_words(FILE*, char**, int*, int&, int); // - FilePointer mode
void write_words(FILE*, char**, int*, int, int); // - FilePointer mode
void read_file(FILE*, const char*); // - FilePointer mode
void free_mem(char**, char**, int*, int);




