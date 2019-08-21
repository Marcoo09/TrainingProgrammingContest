/* Exercise from codeforce: https://codeforces.com/contest/1205/problem/A
*Algorithm:
- Generate array of 2n numbers between 1 and 2n
- For each of its permutation check if every sum of n numbers differ at most one.
- If any return NO
- In first occurrece return Yes and this combination.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm> 

using namespace std;

int factorial(int n) {
	int acum = 1;
	while (n > 0) {
		acum = acum * n;
		n--;
	}
	return acum;
}

//It prints the array in one line
void printArray(int* arr, int n)
{
	for (int i = 0; i < 2 * n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


bool almostEqual(int* currentArr, int n) {
	int val1 = -1;
	int sum2 = 0;
	//First sum of n digits in the permutation.
	for (int i = 0; i < n; i++) {
		sum2 = sum2 + currentArr[i];
	}
	// All other sums of n consecutive digits compared one to another.
	//If any difference between two of them is bigger than 1, it returns false.
	for (int i = 0; i < 2 * n; i++) {
		int sum1 = 0;
		for (int j = 0; j < n; j++) {
			if (i + j < 2 * n) {
				sum1 = sum1 + currentArr[i + j];
			}
			else {
				sum1 = sum1 + currentArr[i + j - 2 * n];
			}
		}
		if (abs(sum2 - sum1) > 1) return false;
		if (sum1 != sum2) {
			if (val1 == -1) val1 = sum1;
			else if (sum1 != val1) return false;
		}
	}
	return true;
}


int main()
{
	freopen("outputAE.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	bool found = false;

	//Initial order of number set
	int* arrOriginal = new int[2 * n];
	for (int i = 0; i < 2 * n; i++) {
		arrOriginal[i] = i + 1;
	}

	//While there are more permutations, check if there is any almostEqual.
	do {
		if (almostEqual(arrOriginal, n))
		{
			found = true;
		}
	} while (!found && next_permutation(arrOriginal, arrOriginal + 2 * n));

	if (found)
	{
		cout << "YES" << endl;
		printArray(arrOriginal, n);
	}
	else
	{
		cout << "NO" << endl;
	}
	delete arrOriginal;

	return 0;
}