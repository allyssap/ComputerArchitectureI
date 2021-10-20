//============================================================================
// Name        : COMP2650_Lab02_poulina.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <stdio.h>
#define MAX 8//Byte = 8 bits
#include "logic.h"
#include "complement.h"
#include"conversion.h"

///receives input from the user
int input(){
	int x;
	scanf(" %d", &x);
	while(x<0 || x>1){
		printf("Error.Please pick 1 or 0\n");
		scanf(" %d", &x);
	}
	return x;
}

void printarray(int array[]){
	for(int i = 0; i<MAX; i++){
		printf("%d", array[i]);
	}
}
void getbinarynumber(int arr[]){
	for(int i=0 ; i<MAX ; i++){
		printf("\nx%d= ", i);
		arr[i] = input();
	}
}

void get2binarynumbers(int arr1[], int arr2[]){
	printf("Enter the first binary number:");
	getbinarynumber(arr1);
	printf("Enter the second binary number:");
	getbinarynumber(arr2);
}

int base_return(){
	int i;
	while(1){
		printf("Please enter the output base: \n");
		printf("1)Binary\n2)Octal\n3)Decimal\n4)Hexadecimal\n");
		scanf(" %d", &i);
		if(i < 1 || i > 4){
			printf("Invalid choice. Try again\n");
		}
		else{
			return i;
		}
	}
}

void return_conversion(int i, int result[]){
	printf(" is ");
	switch(i){
		case 1:
			printarray(result);
			break;
		case 2:
			to_octal(result);
			break;
		case 3:
			to_decimal(result);
			break;
		case 4:
			to_hexadecimal(result);
			break;
	}
}

int main(void){
	setbuf(stdout, NULL);
	int x[MAX];
	int y[MAX];
	int result[MAX];
	int command;
	int returnval;
	///Enter the command number 0, 1, 2

	while(1){
		printf("\nEnter the command number:\n\t 0)  Exit\n\t 1)  AND\n\t 2)  OR\n\t 3)  NOT\n\t 4)  1's  Complement\n\t 5)  2's Complement\n\t 6)  2's Complement* ");
			scanf(" %d", &command);
		switch(command){
			case 0:
				printf("Exiting...");
				return 0;

			case 1:
				///AND
				get2binarynumbers(x,y);
				returnval = base_return();
				func_and(x, y, result);
				printarray(x);
				printf(" AND ");
				printarray(y);
				return_conversion(returnval, result);
				break;

			case 2:
				///OR
				get2binarynumbers(x,y);
				returnval = base_return();
				func_or(x, y, result);
				printarray(x);
				printf(" OR ");
				printarray(y);
				return_conversion(returnval, result);
				break;

			case 3:
				///NOT
				printf("Enter a binary number:");
				getbinarynumber(x);
				returnval = base_return();
				func_not(x, result);
				printf("NOT ");
				printarray(x);
				return_conversion(returnval, result);
				break;

			case 4:
				///1's complement
				printf("Enter a binary number:");
				getbinarynumber(x);
				returnval = base_return();
				func_1s_comp(x,result);
				printf("1's Complement of ");
				printarray(x);
				return_conversion(returnval, result);
				break;

			case 5:
				///2's complement
				printf("Enter a binary number:");
				getbinarynumber(x);
				returnval = base_return();
				func_2s_comp(x,result);
				printf("2's Complement of ");
				printarray(x);
				return_conversion(returnval, result);
				break;

			case 6:
				///2's complement*
				printf("Enter a binary number:");
				getbinarynumber(x);
				returnval = base_return();
				func_2s_comp_star(x,result);
				printf("2's Complement* of ");
				printarray(x);
				return_conversion(returnval, result);
				break;

			default:
				printf("Please pick one of the command options\n");
				break;
		}
	}
}

