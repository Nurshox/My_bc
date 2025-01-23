#ifndef STRUCTS_H
#define STRUCTS_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_nums
{
    char*num;
    struct s_nums*next;
} s_nums;

#endif