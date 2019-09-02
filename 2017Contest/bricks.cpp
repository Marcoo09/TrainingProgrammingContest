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

int getLessCuttedBricks(vector<vector<int>> wall)
{
    int size = wall.size();
    int colSize = wall[0].size();
    int minCuttedBricks = -1;
    for (int j = 0; j < colSize; j++)
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (wall[i][j] == 1)
            {
                counter++;
            }
        }
        if ((counter < minCuttedBricks) || minCuttedBricks == -1)
        {
            minCuttedBricks = counter;
        }
    }
    return minCuttedBricks;
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
        vector<vector<int>> wall;
        for (int j = 0; j < quantityOfRows; j++)
        {
            vector<int> myVector;
            string line;
            getline(cin, line);
            for (int i = 0; i < line.length(); i++)
            {
                char character = line[i];
                if (character != ' ')
                {
                    int brickWidth = character - 48;
                    while (brickWidth > 0)
                    {
                        myVector.pb(1);
                        brickWidth--;
                    }
                    myVector.pb(0);
                }
            }
            wall.pb(myVector);
        }
        cout << "Caso " << i + 1 << ": " << getLessCuttedBricks(wall) << endl;
    }
    return 0;
}
