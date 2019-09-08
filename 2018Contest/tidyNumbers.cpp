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
#include <iostream>
using namespace std;

bool isATidyNumber(int n)
{
    //int to string
    stringstream ss;
    ss << n;
    string str = ss.str();
    //int to string
    int last = -1;
    for (int i = 0; i < str.length(); i++)
    {
        char currentChar = str[i];
        int currentNumber = (int)currentChar - 48;
        if (currentNumber < last)
        {
            return false;
        }
        else
        {
            last = currentNumber;
        }
    }
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++)
    {
        int majorIntCounted;
        cin >> majorIntCounted;
        bool founded = false;
        while (majorIntCounted > 1 && !founded)
        {
            if (isATidyNumber(majorIntCounted))
            {
                founded = true;
            }
            else
            {
                majorIntCounted--;
            }
        }
        cout << "Caso #" << i << ": " << majorIntCounted << endl;
    }
}