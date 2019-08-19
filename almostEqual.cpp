/*
Algorithm:
- Generate every permutation of 2n numbers between 1 and 2n
- For each of these permutation check if every sum of n numbers differ at most one.
- If any return NO
- In first occurrece return Yes and this combination.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    bool find = false;
    int permToPrint[];

    scanf("%d", &n);

    int quantityOfPermutations = factorial(n * 2);

    int[quantityOfPermutations][2 * n] everyPermutation = generatePermutations(2 * n);

    for (int i = 0; i < quantityOfPermutations && !found; i++)
    {
        int[] currentPermutation = everyPermutation[i];

        if (almostEqual(currentPermutation, n))
        {
            found = true;
            permToPrint = currentPermutation;
        }
    }

    if (found)
    {
        cout << "YES" << endl;
        printArray(permToPrint);
    }
    else
    {
        cout << "NO" << endl;
    }
}

//It verifies if each sum of n elements differ in at most 1
bool almostEqual(int[] arr, int n)
{
    //It missing to implement th9is algorithm
}

//It generates every permutations between 1 - maxNumber
int[][] generatePermutations(int maxNumber)
{
    //It missing to implement this algorithm
}

//It prints the array in one line
void printArray(int[] arr)
{
    for (int i; i < sizeOf(arr); i++)
    {
        cout << arr[i] << " " << end;
    }
}
