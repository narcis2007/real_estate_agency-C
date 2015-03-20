/*
 * domain.c
 *
 *  Created on: 2 mar. 2015
 *      Author: Narcis2007
 */
#include<string.h>
#include "domain.h"
#include<malloc.h>

Offer* init_offer(int id, char *type, int surface, int nr_rooms, char *adress,
		int price) {
	Offer* o = malloc(sizeof(Offer)); //memory alocation for the new offer
	if (o == NULL)
		return NULL;
	o->id = id;
	if (strstr(type, "house") == type) {
		o->type = HOUSE;
	} else if (strstr(type, "apartment") == type) {
		o->type = APARTMENT;
	} else if (strstr(type, "penthouse") == type) {
		o->type = PENTHOUSE;
	}
	o->surface = surface;
	o->nr_rooms = nr_rooms;
	o->adress = malloc(sizeof(char) * (strlen(adress) + 1)); //memory alocation for the adress
	strcpy(o->adress, adress);
	o->price = price;
	return o; //return the pointer to the offer

}
void destroy_offer(Offer* offer) {
	//frees the memory occupied by the offer
	if (offer->adress != NULL) {
		free(offer->adress);
		offer->adress = NULL;
	}
	if (offer != NULL)
		free(offer);
	offer = NULL;
}
