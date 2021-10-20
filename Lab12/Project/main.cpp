//============================================================================
// Name        : Comp2650_Lab12_poulina.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int choosenumber(){
	int choice;
	scanf(" %d",&choice);
	return choice;
}

void power(int dec, int pwr){
	int product;

	product = dec<<pwr;

	printf("%d*(2^%d) = %d\n", dec, pwr, product);
}

void divi(int dec, int pwr){
	int product;

	product = dec>>pwr;

	printf("%d/(2^%d) = %d\n", dec, pwr, product);
}

int main (void){
	setbuf(stdout, NULL);

	int dec;
	int pwr;

    int menu_item=-1;
    while(menu_item!=0)
    {
        printf("Enter the encoding command number:\n0) Exit\n1) Powers of 2\n2) Divisions of 2\n");
        scanf(" %d",&menu_item);
        if (menu_item==1){
        	printf("Enter a decimal number:\n");
        	dec = choosenumber();
        	printf("Enter a power number:\n");
        	pwr = choosenumber();

        	power(dec, pwr);
        }
        else if(menu_item == 2){
        	printf("Enter a decimal number:\n");
			dec = choosenumber();
			printf("Enter a divisor number:\n");
			pwr = choosenumber();

			divi(dec, pwr);
        }
        else if(menu_item!=0)
            printf("Error, invalid command!\n");
    }
}
