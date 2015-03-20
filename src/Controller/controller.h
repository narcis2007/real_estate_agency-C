/*
 * controller.h
 *
 *  Created on: 2 mar. 2015
 *      Author: Narcis2007
 */

#ifndef LAB4_SRC_CONTROLLER_CONTROLLER_H_
#define LAB4_SRC_CONTROLLER_CONTROLLER_H_
#include "../Repository/repository.h"

void add_offer(int id, char *type, int surface, int nr_rooms, char *adress,
		int price);	//adds a new offer in the aplication with the given fields

void update_offer(int id, char *type, int surface, int nr_rooms, char *adress,
		int price);	//updates an existing offer with the given fields; raises an error if the id doesn't exist

void delete_offer(int id); //deletes an offer with the given id; raises an error if the id doesn't exists

Vector* filter_by(char* field, int value); //returns a pointer to a Vector which contains the filtered data

#endif /* LAB4_SRC_CONTROLLER_CONTROLLER_H_ */
