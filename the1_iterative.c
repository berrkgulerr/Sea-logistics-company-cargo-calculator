#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "the1_iterative.h"

#define MAX_CUST_REQUIREMENT 1000
#define MAX_SHIP_TYPE_COUNT 10
#define MAX_CUST_COUNT 10


int min_ships_required_iterative(int ship_types[], int ship_type_count, int customer_requirement) {
   int ships[1000];
	int i,j,min;
   ships[0] = 0;
   
   for(j=1;j<=customer_requirement;j++) {
      min = 10000;    
      for(i=0;i<ship_type_count;i++) {
         if(j>=ship_types[i] && (ships[j-ship_types[i]]+1) < min)
            min = ships[j-ship_types[i]]+1;
      }
      ships[j] = min;
   }
   return ships[customer_requirement];
}
