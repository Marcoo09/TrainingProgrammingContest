/* Exercise from codeforce: https://codeforces.com/contest/1205/problem/A
*Algorithm:
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
    int currentIndex = 0;
    int lastSum = -1;
    int nextSum = 0;
    int counter = 0;
    for (int i = currentIndex; i < sizeof(arr); i++)
    {
        if (counter < n)
        {
            nextSum += arr[i];
            counter++;
        }
        else
        {
            if (lastSum != -1 && fabs(nextSum - lastSum) > 1)
            {
                return false;
            }
            else
            {
                counter = 0;
                i = ++currentIndex;
                lastSum = nextSum;
                nextSum = 0;
            }
        }
    }

    return true;
}

//It generates every permutations between 1 - maxNumber
int[][] generatePermutations(int maxNumber)
{
    //Fill the basic array to then generate the permutations
    int[] orderedArray = new int[maxNumber];
    for (int i = 1; i <= maxNumber)
    {
        orderedArray[i - 1] = i;
    }
    return permute(orderedArray);
    //It missing to implement this algorithm
}

//algorithm found in: https://stackoverflow.com/questions/2920315/permutation-of-array
int[][] permute(int[] nums)
{
    int[][] results = new int[][];
    if (sizeof(nums) == 0)
    {
        return results;
    }
    int[] result = new ArrayList<>();
    dfs(nums, results, result);
    return results;
}

void dfs(int[] nums, int[][] results, int[] result)
{
    if (sizeof(nums) == sizeof(result))
    {
        int[] temp = result;
        add(temp, results);
    }
    for (int i = 0; i < sizeof(nums); i++)
    {
        if (!contains(nums[i], result))
        {
            add(nums[i], result);
            dfs(nums, results, result);
            remove(result, sizeof(result) - 1);
        }
    }
}

//It prints the array in one line
void printArray(int[] arr)
{
    for (int i; i < sizeOf(arr); i++)
    {
        cout << arr[i] << " " << end;
    }
}
