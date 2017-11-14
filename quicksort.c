#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

void quickSort(int[],int,int);
int main(int argc, char** argv)
{
	//srand(time(NULL));
	const int LENGTH = 1000000;
	int testArray[LENGTH];// = {0,1,2,3,4,6,5};
	for (int i = 0; i < LENGTH; i++) testArray[i] = rand();
	quickSort(testArray, 0, LENGTH - 1);
	//for (int i = 0; i < LENGTH; i++) printf("%d\n",testArray[i]);
	//printf("\n");
}
void quickSort(int array[], int l, int r)
{
	
	//printf("presort L: %d, R: %d || ",l,r); for (int i = 0; i <= (r-l); i++) printf("%d ",array[l+i]); printf("\n");
	if (r - l < 1) return;
	int *data = malloc(sizeof(int) * (r - l + 1));
	int pivot = array[l];
	int lCount = 0;
	int rCount = r - l;
	for (int i = l + 1; i <= r; i++) {
		if (array[i] < pivot) data[lCount++] = array[i];
		else data[rCount--] = array[i];
	}
	data[lCount] = pivot;
	memcpy(array + l, data, sizeof(int) * (r - l + 1));
	//free(data);
	//printf("postsort "); for (int i = 0; i <= (r-l); i++) printf("%d ",array[l+i]); printf("\n");
	quickSort(array, l, lCount + l); quickSort(array, rCount + l + 1, r);
	return;
}