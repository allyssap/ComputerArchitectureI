/*
 * conversion.cpp
 *
 *  Created on: Feb. 2, 2021
 *      Author: pouli
 */
#define MAX 8
#include "conversion.h"
#include<stdio.h>
#include <math.h>


void reversearr(int a[], int size){
	int temp[size];
	for(int i = 0; i<size; i++){
		temp[i] = a[i];
	}
	for(int i = 0; i<size; i++){
			a[i] = temp[(size-1)-i];
	}
}


//2^3
void to_octal(int a[]){
	int count = 0;
	int temp[3];
	int b[MAX+1];
	b[0] = 0;
	for(int i = 0; i<MAX; i++){
		b[i+1] = a[i];
	}

	for(int i=0; i<=MAX; i++){
		temp[i%3] = b[i];
		count++;
		if(count == 3){
			count = 0;
			reversearr(temp, 3);
			int sum = 0;
			int j = 0;
			while(temp[j] == 1 || temp[j]== 0){
				sum += temp[j]*(pow(2,j));
				j++;
			}
				printf("%d", sum);
		}
	}
}
void to_decimal(int a[]){
	reversearr(a, MAX);
	int sum = 0;
	int i = 0;
	while(a[i] == 1 || a[i]== 0){
		sum += a[i]*(pow(2,i));
		i++;
	}
	printf("%d", sum);
}

//2^4
void to_hexadecimal(int a[]){
	int count =0;
	int temp[4];
	for(int i=0; i<MAX; i++){
			temp[i%4] = a[i];
			count++;
			if(count == 4){
				count = 0;
				reversearr(temp, 4);
				int sum = 0;
				int j = 0;
				while(temp[j] == 1 || temp[j]== 0){
					sum += temp[j]*(pow(2,j));
					j++;
				}
				if(sum>9){
					printf("%X", sum);
				}
				else{
					printf("%d", sum);
				}
			}
		}
}



