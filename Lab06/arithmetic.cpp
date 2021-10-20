/*
 * arithmetic.cpp
 *
 *  Created on: Feb. 9, 2021
 *      Author: pouli
 */
#include <stdio.h>
#include "arithmetic.h"
#include "complement.h"
#define MAX 8//Byte = 8 bits


bool higher_magnitude(int a[], int b[]){
	///return 1 if a is bigger than b
	for(int i = 1; i<MAX; i++){
		if(a[i] > b[i]){
			return true;
		}
		else if(a[i] < b[i]){
			return false;
		}
	}
	///else return 0
	return false;
}

void add(int a[], int b[], int result[], int carry){
	///start at end of both arrays
	for(int i = MAX-1; i >= 0; i--){
		///1+0---->cause carry if carry ==1 if carry == 1 0 else 1
		if(a[i] == 1 && b[i] == 0){
			if(carry == 1){
				result[i] = 0;
			}
			else{
				result[i] = 1;
			}
		}
		/// 1+1 ---> Always cause carry if carry ==1 1 else 0
		else if(a[i] == 1 && b[i] == 1){
			if(carry == 1){
				carry = 1;
				result[i] = 1;
			}
			else{
				carry = 1;
				result[i] = 0;
			}
		}
		/// 0 + 1  ---->cause carry if carry ==1 if carry==1 0 else 1
		else if(a[i] == 0 && b[i] == 1){
			if(carry == 1){
				carry = 1;
				result[i] = 0;
			}
			else{
				result[i] = 1;
			}
		}
		/// 0+0  ----> if carry = 1 , 1 else 0
		else{
			if(carry == 1){
				carry = 0;
				result[i] = 1;
			}
			else{
				result[i] = 0;
			}
		}
	}

}


void func_signed_mag_addition(int a[], int b[], int result[]){

	int carry=0;
	int sign, bigger;
	if(a[0] == b[0]){
		result[0] = a[0];
			///add regularly
		for(int i = MAX-1; i>=0; i--){
			result[i] = a[i] + b[i] + carry;
			if(result[i] > 1){
				carry = 1;
				result[i] %= 2;
			}
		}
		if(result[0] != a[0]){
			printf("\nOverflow Error\n");
		}
	}
	else{
		///compare larger number
		///keep sign of bigger
		for(int i=1; i<MAX; i++){
			if(a[i] > b[i]){
				sign = a[i];
				bigger = 0;
				break;
			}
			else if(b[i] > a[i]){
				sign = b[i];
				break;
				bigger = 1;
			}
			result[0] = sign;
		}
		///subtract smaller from bigger
		if(bigger == 0){
			//a - b
			func_signed_mag_subtraction(a,b,result);
		}
		else{
			///b-a
			func_signed_mag_subtraction(b,a,result);
		}

	}
}
void func_signed_mag_subtraction(int a[], int b[], int result[]){
	func_2s_comp(b, b);
	func_signed_mag_addition(a,b,result);
}





void func_signed_2s_addition(int a[], int b[], int result[]){
	int carry = 0;

	///both negative
	if(a[0] == 1 && b[0]== 1){
		///printf("\n2");
		///both a and b are negative in signed magnitude
		///add both complements
		func_2s_comp(a, a);
		func_2s_comp(b, b);
		add(a, b, result, carry);
		result[0] = 1;
		carry = 0;
	}
	///both positive
	else if(a[0] == 0 && b[0]== 0){
		////printf("3\n");
		add(a, b, result, carry);
		carry = 0;
	}
	///a is bigger than b
	else if(higher_magnitude(a, b)){
		////printf("4\n");
		///add 2s complement of b
		func_2s_comp(b, b);
		//adding logic here
		add(a, b, result, carry);
		carry = 0;
	}
	///a is smaller than b
	else if(!higher_magnitude(a, b)){
		 ////printf("5\n");
		carry = 0;
		///add 2s complement of b to a
		func_2s_comp(b, b);
		//adding logic here
		add(a, b, result, carry);
	}
	///depends i think
	if(carry == 1){
		///if final carry is generated than the result is positive in its true form
		///else the result is negative in its 2's complement form
		func_2s_comp(result, result);
		}
}
void func_signed_2s_subtraction(int a[], int b[], int result[]){
	int carry = 0;
	func_2s_comp(b, b);

	add(a, b, result, carry);
	if(carry == 1){
		func_2s_comp(result, result);
	}
}
