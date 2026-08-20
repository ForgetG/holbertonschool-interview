#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void radix_sort(int *array, size_t size);
void counting_sort(int *array, size_t size, int exp, int *buffer);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
