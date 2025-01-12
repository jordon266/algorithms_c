#include <stdio.h>

/* making a function that given an input of an array and the amount of numbers in the array, the output will be a sorted array. This will be done via the insertion sort algorithm */

int* insertion_sort(int array[], int n){
	for(int i = 1; i < n;i++){
		int key = array[i];
		int j = i -1;
		while(j>=0 && key<array[j]){
			array[j+1] = array[j];
			j-=1;
		}
		array[j+1] = key;
	}
	return array;
}

int main(){
	int arr [] = {4,3,6,2,34,235,6,231};
	printf("Printing Unsorted Array\n");
	for(int i =0;i < 8;i++){
		printf("%d ",arr[i]);
	}
	printf("\nPrinting sorted Arrays\n");
	int size = (sizeof(arr)/sizeof(arr[0]));
	int * sorted_array = insertion_sort(arr,size);
	for(int i = 0; i < size;i++){
		printf("%d ",sorted_array[i]);
	}
	return 0;
}	