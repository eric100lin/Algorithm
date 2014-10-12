#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned start;
	unsigned end;
	int sum;
} max_subarray;

max_subarray find_maximum_subarray(int A[], unsigned int length) {
	int i;
	int local_start = 0, local_sum = 0;
	max_subarray best;
	best.sum = -INT_MAX;

	for (i = 0; i < length; i++)
	{
		local_sum += A[i];

		if (local_sum>best.sum)
		{
			best.start = local_start;
			best.end = i;
			best.sum = local_sum;
		}

		if (local_sum <= 0)
		{
			local_start = i + 1;
			local_sum = 0;
		}
	}

	return best;
}

int main(int argc, char **argv)
{
	int A[16] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	max_subarray max = find_maximum_subarray(A, 16);
	printf("max_subarray is A[%d..%d] = %d\n", max.start, max.end, max.sum);
	return 0;
}