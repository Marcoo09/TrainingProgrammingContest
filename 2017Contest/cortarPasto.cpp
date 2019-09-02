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
typedef pair<bool, bool> piiBool;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#include <iostream>

pii getMinValueIndex(int **matrix, int length, int width)
{
    int min = matrix[0][0];
    pii returnedValue;
    returnedValue.first = 0;
    returnedValue.second = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((matrix[i][j] < min && matrix[i][j] != 0) || min == 0)
            {
                returnedValue.first = i;
                returnedValue.second = j;
            }
        }
    }

    return returnedValue;
}

piiBool checkIfAllInRowOrColumnAreEqual(int i, int j, int numberToCompare, int **matrix, int length, int width)
{
    piiBool returnedValue;
    returnedValue.first = true;
    returnedValue.second = true;
    for (int p = 0; p < width; p++)
    {
        if (matrix[i][p] != numberToCompare && matrix[i][p] != 0)
        {
            returnedValue.first = false;
        }
    }
    for (int s = 0; s < length; s++)
    {
        if (matrix[s][j] != numberToCompare && matrix[s][j] != 0)
        {
            returnedValue.second = false;
        }
    }
    return returnedValue;
}

bool IsAValidCourt(int **matrix, int length, int width)
{
    int quantityOfNodes = length * width;
    while (quantityOfNodes > 0)
    {
        pii minValue = getMinValueIndex(matrix, length, width);
        int iIndex = minValue.first;
        int jIndex = minValue.second;
        piiBool checkInAxis = checkIfAllInRowOrColumnAreEqual(iIndex, jIndex, matrix[iIndex][jIndex], matrix, length, width);
        if (checkInAxis.first || checkInAxis.second)
        {
            if (checkInAxis.first)
            {
                for (int j = 0; j < width; j++)
                {
                    matrix[iIndex][j] = 0;
                    quantityOfNodes--;
                }
            }
            if (checkInAxis.second)
            {
                for (int i = 0; i < length; i++)
                {
                    matrix[i][jIndex] = 0;
                    quantityOfNodes--;
                }
            }
        }
        else
        {
            return false;
        }
    }
    return true;
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

    return 0;
}