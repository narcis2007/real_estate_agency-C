/*
 * validator.c
 *
 *  Created on: 8 mar. 2015
 *      Author: Narcis2007
 */
#include<error.h>
#include<errno.h>
#include "../Domain/domain.h"
#include "../utils/utils.h"
#include<stdio.h>

void check_id_exists(int id) {
	Vector* v = get_offer_list();
	if (v == NULL)
		return;
	E e;
	int n = size(v), i, ok = 0;
	for (i = 0; i < n; i++) {
		e = get_element(v, i);
		if (((Offer*) e)->id == id)
			ok = 1;
	}
	if (ok == 0)
		errno = EINVAL;
	destroy_vector(v);
}
void check_id_available(int id) {
	Vector* v = get_offer_list();
	if (v == NULL)
		return;
	E e;
	int n = size(v), i, ok = 1;
	for (i = 0; i < n; i++) {
		e = get_element(v, i);
		if (((Offer*) e)->id == id)
			ok = 0;
	}
	if (ok == 0)
		errno = EINVAL;
	destroy_vector(v);
}
void validate_type(char *type) {
	int ok = 0;
	if (strstr(type, "house") == type || strstr(type, "penthouse") == type
			|| strstr(type, "apartment") == type)
		ok = 1;
	if (ok == 0)
		errno = EINVAL;
}
void validate_filter_entry(char *field, int value) {
	int ok = 0;
	if (strstr(field, "price") == field || strstr(field, "surface") == field)
		ok = 1;
	if (ok == 0 || value <= 0)
		errno = EINVAL;
}
void validate_sorting_fields(char* field, char* mode) {
	int ok = 1;
	if (strstr(field, "price") == NULL && strstr(field, "type") == NULL)
		ok = 0;
	if (strstr(mode, "ascending") == NULL && strstr(mode, "descending") == NULL)
		ok = 0;
	if (ok == 0)
		errno = EINVAL;

}
void validate_entry(char *type, int surface, int nr_rooms, char *adress,
		int price) {

	validate_type(type);
	if (surface <= 0 || nr_rooms <= 0 || price <= 0||adress==NULL)
		errno = EINVAL;

	if (errno != 0)
		return;

}
