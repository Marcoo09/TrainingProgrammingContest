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

bool compareInts(int i1, int i2)
{
    return (i1 < i2);
}

int main()
{
    int cases;             //Between 1 - 20
    int quantityOfColumns; // Between 1 - 100

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        vector<int> columns;

        cin >> quantityOfColumns;
        for (int i = 0; i < quantityOfColumns; i++)
        {
            int quantityOfNodesInColumn;
            cin >> quantityOfNodesInColumn;
            columns.pb(quantityOfNodesInColumn);
        }

        sort(columns.begin(), columns.end(), compareInts);

        cout << "Caso " << i + 1 << ": ";
        int size = columns.size();
        for (int i = 0; i < size; i++)
        {
            int currentColumn = columns[i];
            cout << currentColumn << " ";
        }
        cout << endl;
    }
    return 0;
}