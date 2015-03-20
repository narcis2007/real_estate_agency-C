/*
 * utils.h
 *
 *  Created on: 5 mar. 2015
 *      Author: Narcis2007
 */

#ifndef LAB4_SRC_UTILS_UTILS_H_
#define LAB4_SRC_UTILS_UTILS_H_
#include "../Domain/domain.h"
#include<stdlib.h>

typedef void* E;

typedef struct vector {
	int n;
	E *element;
	int capacity;
} Vector;
void init_vector(Vector *v); //initializes the vector atributes
void push_back(Vector *v, E e); //adds the element e in the vector
int size(const Vector *v); //return the number of elements in the vector
E get_element(const Vector* v, int i); //return a void pointer to the element in the i location
void set_element(Vector* v, int i, E e); //puts the element e in the location i
void destroy_vector(Vector *v); //frees the memory
typedef int (*Function2)(E, E);
typedef int (*Function3)(E, E, E);
int ascending(E a, E b, Function2 f); //functons that check the order of the elements a and b
int descending(E a, E b, Function2 f);
void my_sort(Vector* v, Function2 compare_function, Function3 mode); //sorts the vector by the functions given as parameters

#endif /* LAB4_SRC_UTILS_UTILS_H_ */
