/*
 * validator.h
 *
 *  Created on: 8 mar. 2015
 *      Author: Narcis2007
 */

#ifndef LAB4_SRC_VALIDATOR_VALIDATOR_H_
#define LAB4_SRC_VALIDATOR_VALIDATOR_H_

void check_id_exists(int id); //if the id doesn not exist in the repository raises an error
void check_id_available(int id); //if the id exists in the repository raises an error
void validate_entry(char *type, int surface, int nr_rooms, char *adress,
		int price);	//if the data doesn't have the proper attributes it raises an error
void validate_filter_entry(char *field, int value);	//-||-

#endif /* LAB4_SRC_VALIDATOR_VALIDATOR_H_ */
