#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_recursive.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

/* 
	+ Function arguments are:
		++ ship_types:				Array of ship types. Ship type is decided by ship capacity, it is a conceptual thing.
		++ ship_type_count:			Length of ship types array.
		++ customer_requirement:	Load requirement for a single customer.

	+ Returns:	
		The minimum number of ships that are required to satisfy given customer load requirement.

	+ Recursive code should work fine with smaller values.
	When values get larger, recursive function returns after some considerable time.

	+ "return -1" is just a placeholder. Please change it after you implemented this function.
*/
int min(int a, int b){
	if(a<=b){
		return a;
	}
	else{
		return b;
	}
}

int min_ships_required_recursive(int ship_types[], int ship_type_count, int customer_requirement) {
	int i,min_ships;
	if(customer_requirement <= 0){
		return 0;
	}
	
	min_ships = 1000000;
	
	for(i=0 ; i < ship_type_count ; i++ ){
		if(ship_types[i] <= customer_requirement){
			min_ships = min(min_ships, (min_ships_required_recursive(ship_types, ship_type_count, (customer_requirement - ship_types[i])) + 1));
		}
	}
	return min_ships;
}
