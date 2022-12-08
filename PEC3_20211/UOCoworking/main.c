/*
*Author: Eugenio Moya
*Date: 06/10/2021
*Descripción: PEC3 2021 1
*Proyectn: UOCoworking
*/

/* System header files */
#include <stdio.h>
#include <stdbool.h>

/* Constant definition*/
#define CENTER1 1					//Category 1 id
#define CENTER2 2					//Category 2 id
#define CENTER3 3					//Category 3 id

#define MAX_COWORKCENTERS 3   		//Number of cowork centers
#define MAX_COWORKERS 2			    //Max. number of coworkers
#define MIN_PRICE 0.0              	//Min. price
#define MIN_DISCOUNT 0.0          	//Min. discount
#define MAX_DISCOUNT 50.0    		//Max. discount


/* User types definition */
typedef enum {STARTUPS, FREELANCERS, RURAL, SPECIALIZED, GENERALIST} tCoworkingType;


/* Main function */
int main() {
	
	/* Declaracition of variables */
	/*Exercise 2.1*/
	float price[3];					//Monthly rental price of a work room [€]
	/*Exercise 2.2*/
	float discount[3];				//Discount on price of the monthly rent [%]
	int numCoworkers;        		//num. of coworkers, they want to rent spaces
	int bestCoworkCenter;    		//best coworking center id
	int numSpaces;					//total spaces
	float totalPrice[3];			//total price of the monthly rent [€]

	/*Data input*/
	/*Exercise 2.3*/
	printf("INPUT DATA\n");
	printf("CENTER 1\n");
	printf("PRICE [EUR]? (A REAL) >> \n");
	scanf("%f",&price[0]);			
	printf("DISCOUNT [0.0%% - 50.0%%]? (A REAL) >> \n");
	scanf("%f",&discount[0]);
	printf("CENTER 2\n");
	printf("PRICE [EUR]? (A REAL) >> \n");
	scanf("%f",&price[1]);			
	printf("DISCOUNT [0.0%% - 50.0%%]? (A REAL) >> \n");
	scanf("%f",&discount[1]);
	printf("CENTER 3\n");
	printf("PRICE [EUR]? (A REAL) >> \n");
	scanf("%f",&price[2]);			
	printf("DISCOUNT [0.0%% - 50.0%%]? (A REAL) >> \n");
	scanf("%f",&discount[2]);
	printf("COWORKERS? (AN INTEGER) >> \n");
	scanf("%d",&numCoworkers);		//num. of coworkers, they want to rent spaces
	
	/*Data validation*/
	//check if are incorrect input data				
	if ((price[0] < MIN_PRICE) || ((discount[0] < MIN_DISCOUNT) || (discount[0] > MAX_DISCOUNT)) || (price[1] < MIN_PRICE) ||
  ((discount[1] < MIN_DISCOUNT) || (discount[1] > MAX_DISCOUNT)) || (price[2] < MIN_PRICE) || ((discount[2] < MIN_DISCOUNT) ||
  (discount[2] > MAX_DISCOUNT))) {
	  printf("INVALID DATA.TRY AGAIN!\n");
	  return 0;
  }
    else {
	}
	/*Data processing*/
	/*Exercise 2.4*/
	/*calculate the number of spaces according to the workers and the maximum capacity*/
	numSpaces= (numCoworkers /MAX_COWORKERS) + (numCoworkers %MAX_COWORKERS); 
	
	/*calculate the total price for each center*/
	
	totalPrice[0]=(price[0]- price[0] * discount[0]/100)*(float)numSpaces;
	totalPrice[1]=(price[1]- price[1] * discount[1]/100)*(float)numSpaces;
	totalPrice[2]=(price[2]- price[2] * discount[2]/100)*(float)numSpaces;
	
	/*choose the cheapest center*/
	if((totalPrice[0] <= totalPrice[1]) && (totalPrice[0] <= totalPrice[2])){
		bestCoworkCenter = CENTER1;
	} else {
		if((totalPrice[1] < totalPrice[0]) && (totalPrice[1] <= totalPrice[2])){
			bestCoworkCenter = CENTER2;  
      } else {       
			if ((totalPrice[2] < totalPrice[0]) && (totalPrice[2] < totalPrice[1])){
				bestCoworkCenter = CENTER3;
			}
		}
	}

		
	/*Data output*/
	/*Exercise 2.5*/
   	printf("RESULTS\n");
	printf("CHEAPEST COWORK CENTER: %d\n",bestCoworkCenter);
	printf("MONTHLY PRICE: ");
	if (bestCoworkCenter == CENTER1) {
		printf("%.2f\n",totalPrice[0]);
	} else {
		if (bestCoworkCenter == CENTER2) {
		printf("%.2f\n",totalPrice[1]);
		} else {	
			if (bestCoworkCenter == CENTER3) {
			printf("%.2f\n",totalPrice[2]);
			} else {
			printf("INVALID DATA. TRY AGAIN!\n");
			}
		}
	}
	
	return 0;
}