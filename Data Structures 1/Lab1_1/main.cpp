#include <iostream>

// T(n) = O(n)
// M(n) = O(n)

int SumArrayRecursive(int arr[], int n)
{
	if (n == 0) return 0;

	return arr[n - 1] + SumArrayRecursive(arr, n-1);
}

int main()
{
	const int SIZE = 5;
	int arr[SIZE] = { 1, 5, 6, 64, 46 };

	std::cout << SumArrayRecursive(arr, SIZE);

	return 0;
}