#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include "the1_serve_cust.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10

int comparator_function(const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

void sort_integer_array(int arr[], int size) {
	qsort(arr, size, sizeof(int), comparator_function);
}

int serve_customers(int min_required_ships[], int customer_count, int available_captain_count) {
	int i;
	qsort(min_required_ships, customer_count, sizeof(int), comparator_function);
	for(i=0; i<customer_count; i++){
		if(available_captain_count >= min_required_ships[i]){
		available_captain_count = available_captain_count - min_required_ships[i];
		}
		else{
			return i;
		}
	}
	return i;
}
