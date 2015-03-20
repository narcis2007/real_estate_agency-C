/*
 * repository.h
 *
 *  Created on: 3 mar. 2015
 *      Author: Narcis2007
 */

#ifndef LAB4_SRC_REPOSITORY_REPOSITORY_H_
#define LAB4_SRC_REPOSITORY_REPOSITORY_H_
#include "../Domain/domain.h"
#include "../utils/utils.h"

void store_offer_file(Offer* offer); //writes the content of the ofer into the file
void rewrite_offers(Vector* v); //deletes the existing data in the file and puts all the offers in the vector into the file

#endif /* LAB4_SRC_REPOSITORY_REPOSITORY_H_ */
