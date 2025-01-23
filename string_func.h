#ifndef MY_STRING_H
#define MY_STRING_H

#include "struct.h"

int _strlen(char*s);
void _strcpy(char*s1, char*s2);
int check_oper(char c);
int parnt_check(char*str, int len);
int handling_errors(char*str);
int is_digit(char c);
int oper_prec(char c);
int my_atoi(char* param_1);
int calculus_func(int num1, int num2, char oper);


#endif