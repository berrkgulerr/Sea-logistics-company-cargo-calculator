#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_read_input.h"
#include "the1_recursive.h"
#include "the1_iterative.h"
#include "the1_serve_cust.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

int available_captain_count;
int ship_type_count;
int customer_count;
int ship_types[MAX_SHIP_TYPE_COUNT];
int customer_requirements[MAX_CUST_COUNT];

int main()
{
	
	int min_required_ships[MAX_CUST_COUNT] = {0};
	int i;
	
	
	/* TEST 1 - RECURSIVE */
	
	read_input();


	for (i = 0; i < customer_count; i++) {
		min_required_ships[i] = min_ships_required_recursive(ship_types, ship_type_count, customer_requirements[i]);

		printf("%d ships required for customer %d\n", min_required_ships[i], i);
	}

	printf("%d\n", serve_customers(min_required_ships, customer_count, available_captain_count));
	

	/* TEST 2 - ITERATIVE */
	
	read_input();


	for (i = 0; i < customer_count; i++) {
		min_required_ships[i] = min_ships_required_iterative(ship_types, ship_type_count, customer_requirements[i]);

		printf("%d ships required for customer %d\n", min_required_ships[i], i);
	}

	printf("%d\n", serve_customers(min_required_ships, customer_count, available_captain_count));
		

    return 0;
}




