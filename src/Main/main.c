/*
 * main.c
 *
 *  Created on: 1 mar. 2015
 *      Author: Narcis2007
 *
 *10. REAL ESTATE AGENCY
 Evelyn owns a real estate agency. Being also the single employee,
 she needs an application to help her manage all the real estates of
 her clients. Each real estate will be stored in the application in the
 following way: type (one of house, apartment, and penthouse),
 surface, number of rooms, address and price. Evelyn needs the
 application to help her in the following ways:

 1. Each time a new offer appears, the application must allow
 her to add it.
 2. Evelyn wants to be able to update an existing real estate by
 modifying its price, its type and so on.
 3. Evelyn would like to be able to delete an existing real estate.
 4. The application should offer the possibility to filter real estates by a given property such as by
 price or by surface.
 5. Evelyn would like to be able to sort real estates by different criteria such as by price or by type
 (both ascending and descending).
 */

#include<stdlib.h>
#include "../UI/ui.h"

int main() {
	run_app(); //starts app
	return 0;
}
