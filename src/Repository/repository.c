/*
 * repository.c
 *
 *  Created on: 3 mar. 2015
 *      Author: Narcis2007
 */
#include<malloc.h>

#include<stdio.h>
#include "repository.h"
#include<string.h>
#include<errno.h>
#include "../Validator/validator.h"

char* get_type_str(Type type) {
	switch (type) { //returns a string reprezentation of the type
	case HOUSE:
		return "house";
	case APARTMENT:
		return "apartment";
	case PENTHOUSE:
		return "penthouse";

	}
}

void store_offer_file(Offer* offer) {
	FILE *f = fopen("data.txt", "a");
	if (f == NULL) { //if the file can't be opened the execution stops
		return;
	}
	fprintf(f, "%d ", offer->id); //to the existing data are added the properties of the offer
	fprintf(f, "%s ", get_type_str(offer->type));
	fprintf(f, "%d ", offer->surface);
	fprintf(f, "%d ", offer->nr_rooms);
	fprintf(f, "%s ", offer->adress);
	fprintf(f, "%d \n", offer->price);
	fflush(f);
	fclose(f);
}

void rewrite_offers(Vector* v) {
	FILE *f = fopen("data.txt", "w");	//opens the file and deletes the content
	if (f == NULL) {
		return;
	}
	int i, n;
	E o;
	n = size(v);
	for (i = 0; i < n; i++) {
		o = get_element(v, i);
		fprintf(f, "%d ", ((Offer*) o)->id);//writes the Offers contained by the Vector in the file
		fprintf(f, "%s ", get_type_str(((Offer*) o)->type));
		fprintf(f, "%d ", ((Offer*) o)->surface);
		fprintf(f, "%d ", ((Offer*) o)->nr_rooms);
		fprintf(f, "%s ", ((Offer*) o)->adress);
		fprintf(f, "%d \n", ((Offer*) o)->price);
	}
	//fflush(f);
	fclose(f);
}

Vector* get_offer_list() {
	//return a pointer to a vector which contains all the offers in the file
	FILE* f = fopen("data.txt", "r");
	if (f == NULL) {
		return NULL;
	}
	Vector* v = malloc(sizeof(Vector)); //memory alocation
	if (v == NULL)
		return NULL;
	init_vector(v);
	Offer * o;
	int id, surface, nr_rooms, price, i = 0;
	char type[33], adress[256];

	while (fscanf(f, "%d %s %d %d %s %d", &id, type, &surface, &nr_rooms,//reads all data from file
			adress, &price) != EOF) {
		o = init_offer(id, type, surface, nr_rooms, adress, price);
		validate_entry(type,surface,nr_rooms,adress,price);
		if (o == NULL||errno!=0) {//if the offfer could not be initialized the execution stops and the data in the vector is destroyed
			destroy_vector(v);
			fclose(f);
			return NULL;
		}

		push_back(v, o);
		i++;
	}
	fclose(f);
	return v;
}

