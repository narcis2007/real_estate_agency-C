/*
 * domain.h
 *
 *  Created on: 2 mar. 2015
 *      Author: Narcis2007
 */

#ifndef LAB4_SRC_DOMAIN_DOMAIN_H_
#define LAB4_SRC_DOMAIN_DOMAIN_H_
enum type {
	HOUSE, APARTMENT, PENTHOUSE
};
typedef enum type Type;

struct offer {
	Type type;
	int id, surface, nr_rooms, price;
	char* adress;

};

typedef struct offer Offer;

Offer* init_offer(int id, char *type, int surface, int nr_rooms, char *adress,
		int price); //return a pointer to an offer which has the given properties

#endif /* LAB4_SRC_DOMAIN_DOMAIN_H_ */
