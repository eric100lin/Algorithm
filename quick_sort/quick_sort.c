#include <stdio.h>
#include <stdlib.h>

void exchange(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int A[], unsigned int start, unsigned int end)
{
	int check;
	int pivot = A[end];
	int idx_smaller = start - 1;

	for (check = start; check < end; check++)
	{
		if (A[check] <= pivot)
		{
			idx_smaller++;
			exchange(&A[idx_smaller], &A[check]);
		}
	}
	exchange(&A[idx_smaller + 1], &A[end]);
	return idx_smaller + 1;
}

void quickSort(int A[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(A, start, end);
		quickSort(A, start, pivot-1);
		quickSort(A, pivot + 1, end);
	}
}

int main(int argc, char **argv)
{
	int A[] = { 2,8,7,1,3,5,6,4 };
	unsigned int lengthA = sizeof(A) / sizeof(int);
	quickSort(A, 0, lengthA-1);

	return 0;
}