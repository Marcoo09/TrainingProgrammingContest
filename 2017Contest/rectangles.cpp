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

bool sumDeriveInOther(pii firstRectangle, pii secondRectangle, pii thirdRectangle)
{
    int fsL = firstRectangle.first;
    int fsW = firstRectangle.second;

    int snL = secondRectangle.first;
    int snW = secondRectangle.second;

    int tdL = thirdRectangle.first;
    int tdW = thirdRectangle.second;

    return (fsL + snL == tdL) ||
           (fsL + tdL == snL) ||
           (snL + tdL == fsL) ||
           (fsW + snW == tdW) ||
           (fsW + tdW == snW) ||
           (snW + tdW == fsW) ||
           (fsW + snL == tdL) || (fsW + snW == tdL) || (fsL + snW == tdL) || (fsL + snW == tdW) || (fsW + snL == tdW) ||
           (fsW + tdL == snL) || (fsW + tdW == snL) || (fsL + tdW == snL) || (fsL + tdW == snW) || (fsW + tdL == snW) ||
           (snW + tdL == fsL) || (snW + tdW == fsL) || (snL + tdW == fsL) || (snL + tdW == fsW) || (snW + tdL == fsW) ||
           (fsL + snW == tdW) || (fsL + snL == tdW) || (fsW + snL == tdW) || (fsW + snL == tdL) || (fsL + snW == tdL) ||
           (fsL + tdW == snW) || (fsL + tdL == snW) || (fsW + tdL == snW) || (fsW + tdL == snL) || (fsL + tdW == snL) ||
           (snL + tdW == fsW) || (snL + tdL == fsW) || (snW + tdL == fsW) || (snW + tdL == fsL) || (snL + tdW == fsL);
}

bool isPossible(vector<pii> rectangles)
{
    int size = rectangles.size();

    pii firstRectangle = rectangles[0];
    pii secondRectangle = rectangles[1];
    pii thirdRectangle = rectangles[2];

    if (((firstRectangle.first == secondRectangle.first || firstRectangle.first == secondRectangle.second) ||
         (firstRectangle.second == secondRectangle.first || firstRectangle.second == secondRectangle.second)) &&
        ((firstRectangle.first == thirdRectangle.first || firstRectangle.first == thirdRectangle.second) ||
         (firstRectangle.second == thirdRectangle.first || firstRectangle.first == thirdRectangle.second)))
    {
        return true;
    }
    else if ((
                 ((firstRectangle.first == secondRectangle.first || firstRectangle.first == secondRectangle.second) ||
                  (firstRectangle.second == secondRectangle.first || firstRectangle.second == secondRectangle.second)) ||
                 ((firstRectangle.first == thirdRectangle.first || firstRectangle.first == thirdRectangle.second) ||
                  (firstRectangle.second == thirdRectangle.first || firstRectangle.second == thirdRectangle.second)) ||
                 ((thirdRectangle.first == secondRectangle.first || thirdRectangle.first == secondRectangle.second) ||
                  (thirdRectangle.second == secondRectangle.first || thirdRectangle.second == secondRectangle.second))) &&
             sumDeriveInOther(firstRectangle, secondRectangle, thirdRectangle))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int cases; //Between 1 - 20
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        vector<pii> rectangles;
        for (int j = 0; j < 3; j++)
        {
            pii rectangle;
            cin >> rectangle.first >> rectangle.second;
            rectangles.pb(rectangle);
        }
        cout << "Caso " << i + 1 << ": ";
        if (isPossible(rectangles))
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
