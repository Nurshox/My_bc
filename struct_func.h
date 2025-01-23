#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#include "struct.h"
#include "string_func.h"

void add_elem(s_nums**num, char*string);
int nums_count(s_nums*n);
void _free(s_nums*head);

#endif