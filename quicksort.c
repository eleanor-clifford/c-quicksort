#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

void quickSort(int[],int,int);
//int mo3pivot(int[],int,int);
void randomTest(int);
void reverseTest(int);
int main(int argc, char** argv)
{
	srand(time(NULL));
	const int LENGTH = 10000000;
	randomTest(LENGTH);
	//reverseTest(LENGTH);

//	int* testArray = malloc(sizeof(int) * LENGTH + 1);
//	for (int i = 0; i < LENGTH; i++) testArray[i] = rand();
//	printf("%d\n",mo3pivot(testArray,0,LENGTH - 1));
}
void randomTest(int LENGTH) 
{

	printf("RANDOM TEST - ARRAY LENGTH: %d\n",LENGTH);
	int* testArray = malloc(sizeof(int) * LENGTH + 1);
	for (int i = 0; i < LENGTH; i++) testArray[i] = rand();
	quickSort(testArray, 0, LENGTH - 1);
	//for (int i = 0; i < LENGTH; i++) printf("%d\n",testArray[i]); 
	printf("SORTED\n");
}
void reverseTest(int LENGTH)
{
	printf("REVERSE TEST - ARRAY LENGTH: %d\n",LENGTH);
	int* testArray = malloc(sizeof(int) * LENGTH + 1);
	for (int i = 0; i < LENGTH; i++) testArray[i] = LENGTH - i;
	quickSort(testArray, 0, LENGTH - 1);
	//for (int i = 0; i < LENGTH; i++) printf("%d\n",testArray[i]); 
	printf("SORTED\n");
}
void quickSort(int array[], int l, int r)
{
	
	//printf("presort L: %d, R: %d || ",l,r); for (int i = 0; i <= (r-l); i++) printf("%d ",array[l+i]); printf("\n");
	if (r - l < 1) return;
	int *data = malloc(sizeof(int) * (r - l + 1));
	int pivot = array[l];
	//int pivot = array[mo3pivot(array,l,r)];
	int lCount = 0;
	int rCount = r - l + 1;
	for (int i = l + 1; i <= r; i++) {
		if (array[i] < pivot) data[lCount++] = array[i];
		else data[--rCount] = array[i];
	}
	data[lCount] = pivot;
	memcpy(array + l, data, sizeof(int) * (r - l + 1));
	free(data);
	quickSort(array, l, lCount + l); quickSort(array, rCount + l, r);
	return;
}
/*
int mo3pivot(int array[], int l, int r) 
{
	int first = array[l];
	int middle = array[(l+r)/2];
	int last = array[r];
	printf("%d %d %d %d %d %d",l,(l+r)/2,r,first,middle,last);
	if (first < middle) {
		if (middle <= last) return (l+r)/2;
		else if (last <= first) return l;
	}
	else {
		if (last >= first) return l;
		else if (middle >= last) return (l+r)/2;
		return r;
	}
}
*/