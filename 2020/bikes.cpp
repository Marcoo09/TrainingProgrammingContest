#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
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
#include <iostream>

int getQuantityOfPeaks(vector<int> arr)
{
    int quantityOfPicks = 0;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        int currentValue = arr[i];
        if (arr[i - 1] < currentValue && arr[i + 1] < currentValue)
        {
            quantityOfPicks++;
        }
    }
    return quantityOfPicks;
}

int main()
{
    int cases; //Between 1 - 20
    cin >> cases;

    for (int i = 1; i <= cases; i++)
    {
        int quantityOfCheckPoints;
        cin >> quantityOfCheckPoints;

        cin.ignore();
        string line;
        getline(cin, line);
        istringstream is(line);
        vector<int> arr;
        int n;
        while (is >> n)
        {
            arr.pb(n);
        }

        int quantityOfPeaks = getQuantityOfPeaks(arr);

        cout << "Case #" << i << ": " << quantityOfPeaks << endl;
    }

    return 0;
}
