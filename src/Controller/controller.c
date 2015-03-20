/*
 * controller.c
 *
 *  Created on: 2 mar. 2015
 *      Author: Narcis2007
 */

#include<string.h>
#include "../Repository/repository.h"
#include<errno.h>
#include "../Validator/validator.h"

void delete_offer(int id) {
	//deletes an offer from file with the given id, if the id doesn't exist raises an error
	Vector* v = get_offer_list(); //pointer to a Vector which contains all the offers
	if (v == NULL)
		return;
	check_id_exists(id); //if the id doesn't exist raises an error
	if (errno != 0)
		return;	//if an error is detected the execution stops
	E o;
	int i, j, n = size(v);
	for (i = 0; i < n; i++) {
		o = get_element(v, i);
		if (id == ((Offer*) o)->id) {//it deletes the the offer with that id from the list
			for (j = i; j < n - 1; j++) {
				o = get_element(v, j + 1);
				set_element(v, j, o);

			}
			(v->n)--;
			break;
		}
	}
	rewrite_offers(v);		//rewrites the file without the deleted offer
	destroy_vector(v);		//frees the memory
}

void update_offer(int id, char *type, int surface, int nr_rooms, char *adress,
		int price) {	//updates an existing offer with new data
	check_id_exists(id);	//if the id doesn't exist raises an error
	validate_entry(type, surface, nr_rooms, adress, price);
	if (errno != 0) {
		return;	//if an error occurs the execution stops
	}
	Offer* o = init_offer(id, type, surface, nr_rooms, adress, price); //pointer to an Offer in memory
	if (o == NULL)
		return;
	Vector* v = get_offer_list(); //a pointer to a Vector which contains all the existing offers
	if (v == NULL)
		return;
	int i, n = size(v);
	for (i = 0; i < n; i++)
		if (id == ((Offer*) get_element(v, i))->id) {
			set_element(v, i, o);	//updating
		}

	rewrite_offers(v);	//the file is updated
	destroy_vector(v);	//frees the memory
}
Vector* filter_by(char* field, int value) {
	//returns a pointer to a Vector which contains the filtered data by the given field which has the value smaller than the given one
	validate_filter_entry(field, value);	//validates the parameters
	if (errno != 0) {	//if an error occurs the execution stops
		return NULL;
	}
	Vector *v = get_offer_list();
	if (v == NULL)
		return NULL;
	Vector *result = malloc(sizeof(Vector*));
	int n = size(v), i;
	E e;
	init_vector(result);
	if (result == NULL || v == NULL)
		return NULL;
	if (strstr(field, "price") == field) {
		for (i = 0; i < n; i++) {
			e = get_element(v, i);
			if (((Offer*) e)->price < value) {

				push_back(result, e);//move the desired offer in another vector
			} else {
				destroy_offer((Offer*) e);//if the offer doesn't have the desired properties the memory is freed and the offer deleted
			}
		}
	} else if (strstr(field, "surface") == field) {
		for (i = 0; i < n; i++) {
			e = get_element(v, i);
			if (((Offer*) e)->surface < value) {
				push_back(result, e);
			} else {
				destroy_offer((Offer*) e);
			}
		}
	}
	if (v->element != NULL)
		free(v->element);//frees the original container but the filtered offers contained by it remain
	free(v);
	return result;	//the remaining offers have to be freed in UI
}
int price_cmp(E a, E b) {
	return ((Offer*) a)->price - ((Offer*) b)->price;//function which compares 2 parameters by price
}
int type_cmp(E a, E b) {
	return strcmp(get_type_str(((Offer*) a)->type),
			get_type_str(((Offer*) b)->type));//function that compares 2 parameters by type (string)
}
Vector* sort_by(char* field, char* mode) {
	//returns a pointer to a Vector which has the sorted data
	validate_sorting_fields(field, mode);
	if (errno != 0)
		return NULL;
	else {
		Vector* v = get_offer_list();
		E compare_function, *mode_function;	//void pointers to functions
		if (v == NULL)
			return NULL;
		if (strcmp(field, "price") == 0)	//assign the pointers to functions
			compare_function = price_cmp;
		if (strcmp(field, "type") == 0)
			compare_function = type_cmp;
		if (strcmp(mode, "ascending") == 0)
			mode_function = ascending;
		if (strcmp(mode, "descending") == 0)
			mode_function = descending;
		my_sort(v, compare_function, mode_function);//sorts a vector using those functions
		return v;
	}

}
void add_offer(int id, char *type, int surface, int nr_rooms, char *adress,
		int price) {
//adds an offer in the aplication
	check_id_available(id);
	validate_entry(type, surface, nr_rooms, adress, price);
	if (errno != 0) {
		return;
	}
	Offer* o = init_offer(id, type, surface, nr_rooms, adress, price);
	if (o == NULL)
		return;
	store_offer_file(o); //updates the file content
	destroy_offer(o);	//frees the memory
}
