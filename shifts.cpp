#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
#include <numeric>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;

long double getQuantityOfAssigmentsOfShiftInWhichTheGuardsAreHappy(long double minHappiness, vector<long double> amountOfHappinesFirst, vector<long double> amountOfHappinesSecond)
{
    long double returnedValue = 0;
    return returnedValue;
}

bool subsetSum(int S[], int n, int sumLeft[], int A[], int k)
{
    // return true if subset is found
    if (checkSum(sumLeft, k))
        return true;

    // base case: no items left
    if (n < 0)
        return false;

    bool res = false;

    // consider current item S[n] and explore all possibilities
    // using backtracking
    for (int i = 0; i < k; i++)
    {
        if (!res && (sumLeft[i] - S[n]) >= 0)
        {
            // mark current element subset
            A[n] = i + 1;

            // add current item to i'th subset
            sumLeft[i] = sumLeft[i] - S[n];

            // recur for remaining items
            res = subsetSum(S, n - 1, sumLeft, A, k);

            // backtrack - remove current item from i'th subset
            sumLeft[i] = sumLeft[i] + S[n];
        }
    }

    // return true if we get solution
    return res;
}

void partition(vector<long double> happinesDummy, vector<long double> amountOfHappinesFirst,
               vector<long double> amountOfHappinesSecond, int subsets)
{
    if (subsets >= happinesDummy.size())
    {
        // get sum of all elements in the set

        int *A = new int[happinesDummy.size()], int *sumLeft = new int[subsets];

        // create an array of size k for each subset and initialize it
        // by their expected sum i.e. sum/k
        for (int i = 0; i < subsets; i++)
            sumLeft[i] = 0;

        // return true if sum is divisible by k and the set S can
        // be divided into k subsets with equal sum
        bool res = subsetSum(happinesDummy, n - 1, sumLeft, A, k);

        // print all k-partitions
        for (int i = 0; i < subsets; i++)
        {
            cout << "Partition " << i << " is: ";
            for (int j = 0; j < happinesDummy.size(); j++)
                if (A[j] == i + 1)
                    cout << happinesDummy[j] << " ";
            cout << endl;
        }
    }
}

int main()
{
    int cases; //Between 1 - 100
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int numberOfShifts;
        long double minHappiness;
        cin >> numberOfShifts >> minHappiness;
        vector<long double> happinesDummy;
        vector<long double> amountOfHappinesFirst;
        vector<long double> amountOfHappinesSecond;
        for (int j = 0; j < numberOfShifts; j++)
        {
            long double happiness;
            cin >> happiness;
            amountOfHappinesFirst.pb(happiness);
            happinesDummy.pb(1);
        }
        for (int j = 0; j < numberOfShifts; j++)
        {
            long double happiness;
            cin >> happiness;
            amountOfHappinesSecond.pb(happiness);
        }
        long double quantity = getQuantityOfAssigmentsOfShiftInWhichTheGuardsAreHappy(minHappiness, amountOfHappinesFirst, amountOfHappinesSecond);
        cout << "Case #" << i + 1 << ": " << quantity << endl;
    }
    return 0;
}