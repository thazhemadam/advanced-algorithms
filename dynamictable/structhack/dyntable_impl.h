#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef DYNTABLE_IMPLH
#define DYNTABLE_IMPLH
#define INCREASE_FACTOR 1.5
#define DECREASE_FACTOR 0.25
/*
 * struct dyntable: represents a dynamic table
 * @size:	size of the dynamic table
 * @count:	number of elements in the dynamic table
 * @data[0]:	the data that is meant to be stored in the dynamic table
 */
struct dyntable {
	int size;
	int count;
	int data[0];
};

void* make_new_dynamic_table(int n);

void push_back(void **dyntable, int element);

void pop_back(void **dyntable);

#endif