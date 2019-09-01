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

bool IsAValidCourt(int **matrix, int length, int width)
{
    bool returnedValue = true;
    return returnedValue;
}

int main()
{
    //The court is a rectangle of  N * M
    //The design is defined with the high of each rectangle of 1 * 1 of the grass
    //Initialy- the grass has a high of 100 mm in all court
    //The couter could change the high of the grass to a value betweem 1 mm and 100 mm

    int cases;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int n, m;
        cin >> n;
        cin >> m;
        int **matrix = new int *[n];
        for (int j = 0; j < n; j++)
        {
            int high;
            int *row = new int[m];
            for (int p = 0; p < m; p++)
            {
                cin >> high;
                row[p] = high;
            }
            matrix[j] = row;
        }
        cout << "Caso " << i + 1 << ": ";
        if (IsAValidCourt(matrix, n, m))
        {
            cout << "SI" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    // // DON'T FORGET TO DELETE THE MATRIX!
    // for(int i = 0; i < N; ++i)
    //     delete matrix[i];
    return 0;
}