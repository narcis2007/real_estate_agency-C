/*
 * ui.c
 *
 *  Created on: 1 mar. 2015
 *      Author: Narcis2007
 */
#include<string.h>
#include<stdio.h>
#include "../Controller/controller.h"
#include<error.h>
#include<errno.h>
#include "../Validator/validator.h"

void add() {
	//type surface nr_rooms (adress1 ...) price

	char type[22], adress[256];
	int id, surface, nr_rooms, price;
	scanf("%d", &id);
	scanf("%s", type);
	scanf("%d", &surface);
	scanf("%d", &nr_rooms);
	scanf("%s", adress);
	scanf("%d", &price);

	add_offer(id, type, surface, nr_rooms, adress, price); //adds an Offer entity into the aplication

	if (errno != 0) {
		perror("Error "); //checks for errors
	}
}

void update() {
	//updates an existing Offer in the aplication
	char type[22], adress[256];
	int id, surface, nr_rooms, price;
	scanf("%d", &id);
	scanf("%s", type);
	scanf("%d", &surface);
	scanf("%d", &nr_rooms);
	scanf("%s", adress);
	scanf("%d", &price);

	update_offer(id, type, surface, nr_rooms, adress, price);

	if (errno != 0) {	//checks for errors
		perror("Error ");
	}
}

void delete() {
	//deletes an offer with the given id
	int id;
	scanf("%d", &id);

	delete_offer(id);
	if (errno != 0)	//checks for errors
		perror("Error");
}
void filter() {
	//filters the Offers by a field and a value

	char field[55];
	int value, n, i;
	scanf("%s", field);
	scanf("%d", &value);

	Vector* v = filter_by(field, value);//receives a pointer the the filtered values
	if (errno != 0)
		perror("Error ");	//checks for errors
	else {
		n = size(v);
		E e;
		for (i = 0; i < n; i++) {
			e = get_element(v, i);   					//displays the offers
			printf("%d %s %d %d %s %d \n", ((Offer*) e)->id,
					get_type_str(((Offer*) e)->type), ((Offer*) e)->surface,
					((Offer*) e)->nr_rooms, ((Offer*) e)->adress,
					((Offer*) e)->price);
		}
		destroy_vector(v);   						//frees the memory
	}

}

void sort() {
	//sorts by a field(price/type) both ascending or descending
	char field[33], mode[33];
	int i, n;
	scanf("%s", field);
	scanf("%s", mode);
	Vector *v = sort_by(field, mode);  //receives a pointer to the sorted offers
	E e;
	n = size(v);
	if (errno != 0) {
		perror("Error "); //checks for errors
	} else {
		for (i = 0; i < n; i++) {
			e = get_element(v, i);					//displays the offers
			printf("%d %s %d %d %s %d \n", ((Offer*) e)->id,
					get_type_str(((Offer*) e)->type), ((Offer*) e)->surface,
					((Offer*) e)->nr_rooms, ((Offer*) e)->adress,
					((Offer*) e)->price);
		}
	}
	destroy_vector(v); //frees the memory
}
void run_app() {
	//calls the proper function for each command given
	setbuf(stdout, NULL);
	char cmd[256];
	while (1) {
		errno = 0;
		printf("\n>");
		scanf("%s", cmd);

		if (strstr(cmd, "add") == cmd) {
			add();
		} else if (strstr(cmd, "update") == cmd) {
			update();
		} else if (strstr(cmd, "exit") == cmd) {
			break;
		} else if (strstr(cmd, "delete") == cmd) {
			delete();
		} else if (strstr(cmd, "filter") == cmd)
			filter();
		else if (strstr(cmd, "sort") == cmd) {
			sort();
		} else {
			perror("unknown cmd");
		}
	}
}
