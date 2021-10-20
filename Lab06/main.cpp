//============================================================================
// Name        : COMP2650_Lab06_poulina.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#define MAX 8//Byte = 8 bits
#include "complement.h"
#include "conversion.h"
#include "arithmetic.h"

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
		printf("\nEnter the command number:\n\t 0)  Exit\n\t 1)  Addition in signed-2's-Complement\n\t 2)  Subtraction in signed-2's-Complement\n\t ");
			scanf(" %d", &command);
		switch(command){
			case 0:
				printf("Exiting...");
				return 0;

			case 1:
				///ADD
				printf("\n");
				get2binarynumbers(x,y);
				returnval = base_return();
				printarray(x);
				printf(" + ");
				printarray(y);
				func_signed_2s_addition(x, y, result);
				return_conversion(returnval, result);
				break;

			case 2:
				///SUB
				get2binarynumbers(x,y);
				returnval = base_return();
				printarray(x);
				printf(" - ");
				printarray(y);

				func_signed_2s_subtraction(x, y, result);
				return_conversion(returnval, result);
				break;

			default:
				printf("Please pick one of the command options\n");
				break;
		}
	}
}

