#include <stdio.h>
#define SIZEOFARRAY(arr) (sizeof(arr)/sizeof((arr)[0]))
/* This program serves as a collection of functions that execute and show binary addition given 2 arrays that represent two binary numbers and returns the sum as an array
in binary */

/* Partial lessons learnt 
	pointer decay - which occurs when passing an array to a function it becomes a pointer. which means sizeof doesnt work inside the function.
*/

/* Before creating a function that can convert from decimal to binary. An function that can evaluate exponentials must be created in order to be used for binary
to decimal conversion function to work*/
int exponent(int n, int power){
	if (power == 0){
		return 1;
	}
	return n * exponent(n, power-1);
}

/* Before creating a function that can add binary numbers, a function that can convert from binary to decimal will be created as well in order to test the validity
	of the binary addition
	Question: why does pointer decay occur?
 */
int bin_to_dec(int* array, int size){
	int dec = 0;
	for(int i = 0; i < size;i++){
		if(array[i] == 1){
			dec += exponent(2,i);
		}
	}
	return dec;
}
/* A recursive version of the binary to decimal conversion can be made will work on this in the future
	recursive function */
int rbin_to_dec(int array[], int pow, int current_index){
	
	if(pow < 0){
		return 0;
	}
	if(array[current_index] == 1){
		return exponent(2,pow) + rbin_to_dec(array,--pow,++current_index);
	}
	return   rbin_to_dec(array,--pow,++current_index);
}

int main(){
	int bin[] = {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0}; // 	binary representation of 57342
	int end_index = SIZEOFARRAY(bin) - 1;
	int start_index = 0;
	int dec = rbin_to_dec(bin,end_index,start_index);
	printf("%d ", end_index); // should print 57342
	return 0;
}