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
#include <iterator>

void print(vector<unsigned long long> print)
{
    for (int i = 0; i < print.size(); i++)
    {
        cout << " " << print[i] << " ";
    }
    cout << endl;
}

vector<unsigned long long> getBusesFor(unsigned long long currentDay, vector<unsigned long long> busRoutes)
{
    vector<unsigned long long> returnArray;
    for (unsigned long long i = 0; i < busRoutes.size(); i++)
    {
        if (currentDay % busRoutes[i] == 0)
        {
            returnArray.pb(busRoutes[i]);
        }
    }
    return returnArray;
}

bool canTakeAllBusesBeginingIn(unsigned long long firstDay, vector<unsigned long long> busRoutes, unsigned long long finishDay)
{
    vector<unsigned long long> busRoutesAux;
    for (unsigned long long i = 0; i < busRoutes.size(); i++)
    {
        busRoutesAux.pb(busRoutes[i]);
    }

    for (unsigned long long i = firstDay; i <= finishDay; i++)
    {
        // cout << "Entre el día " << i << endl;
        vector<unsigned long long> busesToTakeToday = getBusesFor(i, busRoutesAux);
        // cout << "Busses to tak today : ";

        // print(busesToTakeToday);
        if (busesToTakeToday.size() > 0 && busesToTakeToday[0] == busRoutesAux[0])
        {
            vector<unsigned long long> diff;
            //not need to sort since it already sorted
            set_difference(busRoutesAux.begin(), busRoutesAux.end(), busesToTakeToday.begin(), busesToTakeToday.end(),
                           inserter(diff, diff.begin()));
            // cout << "Diff : ";
            // print(diff);

            busRoutesAux = diff;
        }

        // cout << "busRoutesAux : ";
        // print(busRoutesAux);
    }

    return busRoutesAux.size() == 0;
}

unsigned long long getLastDayToTakeBus(vector<unsigned long long> busRoutes, unsigned long long finishDay)
{
    unsigned long long lastDay = 1;

    for (unsigned long long day = 1; day <= finishDay; day++)
    {
        //Copiarlas
        bool canTakeAllBuses = canTakeAllBusesBeginingIn(day, busRoutes, finishDay);
        lastDay = canTakeAllBuses ? day : lastDay;
    }

    return lastDay;
}

int main()
{
    int cases; //Between 1 - 20
    cin >> cases;

    for (int i = 1; i <= cases; i++)
    {
        int quantityOfBuses;
        unsigned long long finishDay;
        cin >> quantityOfBuses >> finishDay;

        cin.ignore();
        string line;
        getline(cin, line);
        istringstream is(line);
        vector<unsigned long long> busRoutes;
        unsigned long long n;
        while (is >> n)
        {
            busRoutes.pb(n);
        }

        unsigned long long lastDay = getLastDayToTakeBus(busRoutes, finishDay);

        cout << "Case #" << i << ": " << lastDay << endl;
    }

    return 0;
}
