/*
 * utils.c
 *
 *  Created on: 5 mar. 2015
 *      Author: Narcis2007
 */
#include<malloc.h>
#include "utils.h"
#include<stdio.h>

void init_vector(Vector *v) {
	v->n = 0;
	v->capacity = 5;
	v->element = malloc(sizeof(E) * (v->capacity));

}

void push_back(Vector *v, E e) {

	if (v->capacity <= v->n) {

		//if there is no space it doubles the capacity - dinamic alocation
		int new_capacity = (2 * (v->capacity)), i;
		E *new_space = malloc(sizeof(E) * new_capacity);
		if (new_space == NULL)
			return;
		for (i = 0; i < v->n; i++) {
			new_space[i] = v->element[i];
		}
		v->capacity = new_capacity;
		free(v->element);
		v->element = new_space;
	}
	v->element[v->n] = e;
	v->n++;
}
int size(const Vector *v) {
	return v->n;
}

E get_element(const Vector *v, int i) {
	return v->element[i];
}

void set_element(Vector* v, int i, E e) {
	v->element[i] = e;

}
void destroy_vector(Vector *v) {

	int i, n = size(v);
	for (i = 0; i < n; i++) {
		if (get_element(v, i) != NULL)
			destroy_offer(((Offer*) get_element(v, i)));
	}
	if (v->element != NULL)
		free(v->element);
	v->element = NULL;
	if (v != NULL)
		free(v);
	v = NULL;
}
int ascending(E a, E b, Function2 f) {
	if (f(a, b) > 0)
		return 1;
	return 0;
}
int descending(E a, E b, Function2 f) {
	if (f(a, b) < 0)
		return 1;
	return 0;
}
void my_sort(Vector* v, Function2 compare_function, Function3 mode) {
	//function that can sort any elements in the vector
	int i, j, n = size(v);
	E a, *b, *t;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++) {
			a = get_element(v, i);
			b = get_element(v, j);
			if (mode(a, b, compare_function) > 0) {
				t = a;
				set_element(v, i, b);
				set_element(v, j, t);
			}
		}
}

