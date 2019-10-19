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
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;

long double getMajor(vector<long double> laws)
{
    long double major = 0;
    for (int i = 0; i < laws.size(); i++)
    {
        if (laws[i] > major)
        {
            major = laws[i];
        }
    }
    return major;
}

int getMajorI(vector<pii> pairsOfResults)
{
    int majorI = 0;
    int majorValue = 0;
    for (int i = 0; i < pairsOfResults.size(); i++)
    {
        if (pairsOfResults[i].second >= majorValue)
        {
            majorValue = pairsOfResults[i].second;
            majorI = pairsOfResults[i].first;
        }
    }
    return majorI;
}

long double xorb(int a, int b)
{
    return a ^ b;
}

long double getLargestK(long double equationLimitation, vector<long double> laws)
{
    long double sum;
    for (long double i = getMajor(laws) > equationLimitation ? getMajor(laws) : equationLimitation; i >= 0; i--)
    {
        sum = 0;
        for (int j = 0; j < laws.size(); j++)
        {
            sum += xorb(laws[j], i);
        }
        if (sum <= equationLimitation)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int cases; //Between 1 - 100
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        long double quantityOfA;
        long double equationLimitation;
        cin >> quantityOfA >> equationLimitation;
        vector<long double> laws;
        for (int j = 0; j < quantityOfA; j++)
        {
            long double law;
            cin >> law;
            laws.pb(law);
        }
        long double largestK = getLargestK(equationLimitation, laws);
        cout << "Case #" << i + 1 << ": " << largestK << endl;
    }
    return 0;
}