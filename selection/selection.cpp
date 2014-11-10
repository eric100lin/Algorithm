#include <iostream>
#include <vector>
#include <array>
using namespace std;

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

int select(int A[], int lengthA, int i)
{
	if (lengthA == 1)
		return A[0];

	unsigned int r = 5;
	unsigned int group = lengthA/r;
	int *M = new int[group];
	for(int g=0; g<group; g++)
	{
		quickSort(A, 0+r*g, r - 1+r*g);
		M[g] = A[2+g*r];
	}
	int m = select(M, group, group / 2);
	delete[] M;
	vector<int> S1, S2, S3;
	for(int idx=0; idx<lengthA; idx++)
	{
		int x = A[idx];
		if(x<m)			S1.push_back(x);
		else if(x==m)	S2.push_back(x);
		else 			S3.push_back(x);
	}
	if (i+1 <= S1.size())	select(S1.data(), S1.size(), i);
	else if(i+1<=(S1.size()+S2.size()))	return m;
	else	select(S3.data(), S3.size(), i - (S1.size() + S2.size()));
}

int main(int argc, char **argv)
{
	int A[] = { 4,1,6,3,1,2,5,7,8,7,6,5,9,1,7,1,3,5,7,6,9,2,4,3,5 };
	unsigned int lengthA = sizeof(A) / sizeof(int);
	//cout << "Select(A,7)=" << select(A, lengthA, 7) << endl;
	cout << "Select(A,13)=" << select(A, lengthA, 13) << endl;
	//cout << "Select(A,22)=" << select(A, lengthA, 22) << endl;
	return 0;
}