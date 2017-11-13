#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quickSort(int[],int,int);
int main(int argc, char** argv)
{
	srand(time(NULL));
	const int LENGTH = 10;
	int testArray[LENGTH];
	for (int i = 0; i < LENGTH; i++) testArray[i] = rand() % 1000;
	quickSort(testArray, 0, sizeof(testArray) / sizeof(int) - 1);
	for (int i = 0; i < LENGTH; i++) printf("%d ",testArray[i]);
	printf("\n");
}
void quickSort(int array[], int l, int r)
{
	if (r - l <= 1) return;
	//printf("%d /",array[l]); for (int i = 0; i <= (r-l); i++) printf("%d ",array[l+i]); // printf("\n");
	int *data = malloc(sizeof(int) * (r - l + 1));
	int pivot = array[l];
	int lCount = 0;
	int rCount = r;
	for (int i = l + 1; i <= r; i++) {
		if (array[i] < pivot) data[lCount++] = array[i];
		else data[rCount--] = array[i];
	}
	data[lCount] = pivot;
	memcpy(array + l, data, sizeof(int) * (r - l + 1));
	free(data);
	quickSort(array, l, lCount); quickSort(array, rCount+1, r);
	return;
}