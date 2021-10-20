/*
 * complement.cpp
 *
 *  Created on: Feb. 2, 2021
 *      Author: pouli
 */

#include"complement.h"
#include"logic.h"
#define MAX 8

///if 0 change to 1, if 1 change to 0
void func_1s_comp(int a[], int result[]){
	func_not(a, result);
}


///use ones complement and add one
void func_2s_comp(int a[], int result[]){
	int carry = 1;
	int ones[MAX];
	func_1s_comp(a, ones);

	for(int i = (MAX-1); i>=0; i--){
		if(carry ==1 && ones[i] == 1){
			result[i] = 0;
			carry =1;
		}
		else if(carry == 1 && ones[i] ==0){
			result[i] = 1;
			carry = 0;
		}
		else{
			result[i] = ones[i];
		}
	}
}

///Start from the right to left until you see digit 1,then	pass it	and	NOT the digits after that. For instance, 2’s complement	of 110100 is 001100.
void func_2s_comp_star(int a[], int result[]){
	func_2s_comp(a, result);
	for(int i = (MAX-1); i>=0; i--){
		result[i] = a[i];
		if(a[i] == 1){
			i--;
			for(int n = i; n>=0; n--){
				if(a[i] == 1){
					result[i] = 0;
				}
				else{
					result[i] = 1;
				}
			}
			break;	//stop the for loop if a[i] == 1
		}
	}
}
