#include <stdio.h>
#include <stdlib.h>
#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)

void maxHeapify(int A[], unsigned int i, unsigned int heap_size)
{
	int largest = i;
	int left = LEFT(i);
	int right = RIGHT(i);
	if (left <= heap_size && A[left - 1] > A[i - 1])
		largest = left;
	if (right <= heap_size && A[right - 1] > A[largest - 1])
		largest = right;

	if (largest!=i)
	{
		int tmp = A[i - 1];
		A[i - 1] = A[largest - 1];
		A[largest - 1] = tmp;
		maxHeapify(A, largest, heap_size);
	}
}

void buildHeap(int A[], unsigned int heap_size)
{
	for (int i = heap_size / 2; i >= 1; i--)
		maxHeapify(A, i, heap_size);
}

void heapSort(int A[], unsigned int heap_size)
{
	buildHeap(A, heap_size);
	for (int i = heap_size; i >= 2; i--)
	{
		int tmp = A[i - 1];
		A[i - 1] = A[1 - 1];
		A[1 - 1] = tmp;
		maxHeapify(A, 1, --heap_size);
	}
}

int main(int argc, char **argv)
{
	int A[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	unsigned int lengthA = sizeof(A) / sizeof(int);
	maxHeapify(A, 2, lengthA);

	int B[] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
	unsigned int lengthB = sizeof(B) / sizeof(int);
	maxHeapify(B, 3, lengthB);

	int C[] = { 4,1,3,2,16,9,10,14,8,7 };
	unsigned int lengthC = sizeof(C) / sizeof(int);
	buildHeap(C, lengthC);

	int AA[] = { 4,1,3,2,16,9,10,14,8,7 };
	unsigned int lengthAA = sizeof(AA) / sizeof(int);
	heapSort(AA, lengthAA);

	return 0;
}