/*
 * logic.cpp
 *
 *  Created on: Feb. 2, 2021
 *      Author: pouli
 */
#include <stdio.h>
#include"logic.h"
#define MAX 8
///prints the array to the console

///if one of the numbers at the index is 0, the result at that index is 0
void func_and(int a[], int b[], int result[]){
	for(int i=0; i<MAX; i++){
		if(a[i] == 0 || b[i] == 0){
			result[i] = 0;
		}
		else{
			result[i] = 1;
		}
	}
}
///if either numbers at the same index are 1, the result at that index is 1 else the result at that index is 0
void func_or(int a[], int b[], int result[]){
	for(int i=0; i<MAX; i++){
			if(a[i] == 1 || b[i] == 1){
				result[i] = 1;
			}
			else{
				result[i] = 0;
			}
		}
}
///if 0 change to 1, if 1 change to 0
void func_not(int a[], int result[]){
	for(int i=0; i<MAX; i++){
		if(a[i] == 0){
			result[i] = 1;
		}
		else{
			result[i] = 0;
		}
	}
}
