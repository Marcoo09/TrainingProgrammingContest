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
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef pair<bool, int> bi;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;

//Without finalize
string largerString(vector<string> strings)
{
    string returnedString;
    int largeOfLonger = 0;
    for (int i = 0; i < strings.size(); i++)
    {
        string currentString = strings[i];
        if (currentString.length() > largeOfLonger)
        {
            returnedString = currentString;
            largeOfLonger = currentString.length();
        }
    }
    return returnedString;
}

string shortestString(vector<string> strings)
{
    string returnedString;
    int largeOfLonger = -1;
    for (int i = 0; i < strings.size(); i++)
    {
        string currentString = strings[i];
        if (currentString.length() < largeOfLonger || largeOfLonger == -1)
        {
            returnedString = currentString;
            largeOfLonger = currentString.length();
        }
    }
    return returnedString;
}

bi couldConvertToEqualAndMovements(string strOrigin, string strToConvert)
{
    bi returnedValue;
    returnedValue.first = false;
    returnedValue.second = -1;
    int sizeStrOrigin = strOrigin.length();
    int sizeStrToConvert = strToConvert.length();
    if (strOrigin == strToConvert)
    {
        returnedValue.first = true;
        returnedValue.second = 0;
    }
    else
    {
        //Algorithm to transform strings
    }
    return returnedValue;
}

bi couldBeReducedToString(string str, vector<string> strings)
{
    bi returnedValue;
    returnedValue.first = true;
    returnedValue.second = -1;
    int counter = 0;
    for (int i = 0; i < strings.size() && returnedValue.first; i++)
    {
        string currentString = strings[0];
        bi couldConvertToEqual = couldConvertToEqualAndMovements(str, currentString);
        if (!couldConvertToEqual.first)
        {
            returnedValue.first = false;
        }
        else
        {
            counter += couldConvertToEqual.second;
        }
    }
    if (returnedValue.first)
    {
        returnedValue.second = counter;
    }
    return returnedValue;
}

int main()
{
    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++)
    {
        int quantityOfCases;
        cin >> quantityOfCases;
        vector<string> strings;
        while (quantityOfCases > 0)
        {
            string line;
            cin >> line;
            strings.pb(line);
            quantityOfCases--;
        }

        bi infoOfStrigns;
        infoOfStrigns.first = false;
        infoOfStrigns.first = false;
        bi bestInfoOfStrings;
        bestInfoOfStrings.first = false;
        bestInfoOfStrings.second = -1;
        for (int i = 0; i < strings.size(); i++)
        {
            string currentString = strings[i];
            infoOfStrigns = couldBeReducedToString(currentString, strings);
            if (infoOfStrigns.first)
            {
                if (bestInfoOfStrings.second == -1 || (bestInfoOfStrings.first > infoOfStrigns.second && infoOfStrigns.second != -1))
                    bestInfoOfStrings = infoOfStrigns;
            }
        }
        if (bestInfoOfStrings.first)
        {
            cout << "Caso #" << cases << ": " << bestInfoOfStrings.second << endl;
        }
        else
        {
            cout << "Caso #" << cases << ": Fegla won" << endl;
        }
    }
}