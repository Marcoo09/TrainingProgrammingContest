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

int getHowManyReadersWillReadThisPage(int page, vector<int> readerIdentifier)
{
    int totalOfReaders = 0;
    for (int i = 0; i < readerIdentifier.size(); i++)
    {
        if (page % readerIdentifier[i] == 0)
        {
            totalOfReaders++;
        }
    }
    return totalOfReaders;
}

bool isTurnedOut(int page, vector<int> pagesTornedOut)
{
    for (int i = 0; i < pagesTornedOut.size(); i++)
    {
        if (pagesTornedOut[i] == page)
        {
            return true;
        }
    }
    return false;
}

int getAllPagesReaded(int pages, vector<int> pagesTornedOut, vector<int> readerIdentifier)
{
    int readedPages = 0;
    for (int i = 1; i <= pages; i++)
    {
        if (!isTurnedOut(i, pagesTornedOut))
        {
            readedPages += getHowManyReadersWillReadThisPage(i, readerIdentifier);
        }
    }
    return readedPages;
}

int main()
{
    int cases; //Between 1 - 100
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int pages;
        int tornedOut;
        int lazyReaders;
        cin >> pages >> tornedOut >> lazyReaders;
        vector<int> pagesTornedOut;
        vector<int> readerIdentifier;
        for (int j = 0; j < tornedOut; j++)
        {
            int pageNumber;
            cin >> pageNumber;
            pagesTornedOut.pb(pageNumber);
        }
        for (int j = 0; j < lazyReaders; j++)
        {
            int identifier;
            cin >> identifier;
            readerIdentifier.pb(identifier);
        }
        int allPagesReaded = getAllPagesReaded(pages, pagesTornedOut, readerIdentifier);
        cout << "Case #" << i + 1 << ": " << allPagesReaded << endl;
    }
    return 0;
}