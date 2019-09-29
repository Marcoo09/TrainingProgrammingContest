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

int getNumberOfChanges(vector<int> heights, int maxNumberOfChanges, int numberOfSections)
{
    int returnedValue = 0;
    int changes = 0;
    int last = heights[0];
    for (int i = 0; i < numberOfSections; i++)
    {
        int current = heights[i];
        if (current != last && maxNumberOfChanges != 0)
        {
            last = current;
            changes++;
        }
        if (changes == maxNumberOfChanges)
        {
            returnedValue++;
            changes = 0;
        }
    }

    return returnedValue;
}

int getNumberOfChanges2(vector<int> heights, int maxNumberOfChanges, int numberOfSections)
{
    int returnedValue = 0;
    int changes = 0;
    int last = heights[numberOfSections - 1];
    for (int i = numberOfSections - 1; i >= 0; i--)
    {
        int current = heights[i];
        if (current != last)
        {
            last = current;
            changes++;
        }

        if (changes == maxNumberOfChanges)
        {
            returnedValue++;
            changes = 0;
        }
    }

    return returnedValue;
}

int main()
{
    int cases; //Between 1 - 20
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int numberOfSections;
        int maxNumberOfChanges;
        cin >> numberOfSections >> maxNumberOfChanges;
        vector<int> heights;
        for (int j = 0; j < numberOfSections; j++)
        {
            int height;
            cin >> height;
            heights.pb(height);
        }

        int quantityOfChanges1 = getNumberOfChanges(heights, maxNumberOfChanges, numberOfSections);
        int quantityOfChanges2 = getNumberOfChanges2(heights, maxNumberOfChanges, numberOfSections);
        int quantityOfChanges;
        if (quantityOfChanges1 > quantityOfChanges2)
        {
            quantityOfChanges = quantityOfChanges2;
        }
        else
        {
            quantityOfChanges = quantityOfChanges1;
        }

        cout << "Case #" << i + 1 << ": " << quantityOfChanges << endl;
    }
    return 0;
}