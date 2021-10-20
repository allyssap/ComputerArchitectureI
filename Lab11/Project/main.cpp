//============================================================================
// Name        : COMP2650_Lab11_poulina.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<math.h>
#define Byte 8

void to_binary(int a,int b[]){
	//code to convert a decimal number to binary
		for(int i=Byte; i>0;i--){
			if(a % 2 == 1){
				b[i] = 1;
			}
			else{
				b[i] = 0;
			}
			a= (int) a/2;
		}
}

void to_Gray(int a,int c[]){
	int binary_number[Byte] = {0};
	to_binary(a, binary_number);
	//code for binary to Gray
	for(int i=0;i<Byte-1; i++){
		if((binary_number[i] == 0 && binary_number[i+1] == 0) || (binary_number[i] == 1 && binary_number[i+1] == 1) ){
			c[i] = 0;
		}
		else{
			c[i] = 1;
		}
	}
	c[Byte-1] = binary_number[Byte-1];
	//code for printing Gray code
	for(int i= 0; i<Byte ; i++){
		printf("%d", c[i]);
	}
}

int main (void){
	setbuf(stdout, NULL);
    int Gray_code[Byte];

    int menu_item=-1;
    while(menu_item!=0)
    {
        printf("Enter the encoding command number:\n0) Exit\n1) Gray code\n");
        scanf(" %d",&menu_item);
        if (menu_item==1)
        {
            printf("Enter a decimal number between 0 and 255 (inclusive):");
            int decimal_number=-1;
            scanf(" %d",&decimal_number);
            while(decimal_number<0||decimal_number>255)
            {
                printf("Error, enter a decimal number between 0 and 255 (inclusive):");
                scanf(" %d",&decimal_number);
            }
            printf("Gray code for %d -> ",decimal_number);
            to_Gray(decimal_number, Gray_code);
            printf("\n");
        }
        else if(menu_item!=0)
            printf("Error, invalid command!\n");
    }
}
