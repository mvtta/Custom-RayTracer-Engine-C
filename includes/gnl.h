#ifndef GNL_H
#define GNL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define NO_LINE 0
#define BUFFER_SIZE 10000

char    *get_next_line(int fd);

#endif