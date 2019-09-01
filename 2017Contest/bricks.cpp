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

int getLessCuttedBricks(vector<vector<string>> wall)
{
    int size = wall.size();
    for (int i = 0; i < size; i++)
    {
        int colSize = wall[i].size();
        for (int j = 0; j < colSize; j++)
        {
            cout << wall[i][j] << " ";
        }
    }
    return 3;
}

int main()
{
    int cases; // Between 1 - 20

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int quantityOfRows; //(1<=f<=10.000)
        //The quantity of bricks of a wall not exceds 20000
        cin >> quantityOfRows;
        vector<vector<string>> wall;
        for (int j = 0; j < quantityOfRows; j++)
        {
            vector<string> myVector;
            string line;
            getline(cin, line);
            myVector.pb(line);
            wall.pb(myVector);
        }
        cout << "Caso " << i + 1 << ": " << getLessCuttedBricks(wall) << endl;
    }
    return 0;
}
