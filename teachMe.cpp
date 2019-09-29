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

bool isAPossiblePair(int *skillsOfA, int *skillsOfB, int quantityOfSkills)
{
    for (int i = 0; i < quantityOfSkills; i++)
    {
        int currentA = skillsOfA[i];
        int currentB = skillsOfB[i];
        if (currentA == 1 && currentB == 0)
        {
            return true;
        }
    }

    return false;
}

int getTotalOfPairs(vector<int *> employees, int quantityOfEmployees, int quantityOfSkills)
{
    vector<pii> pairs;
    for (int i = 0; i < quantityOfEmployees; i++)
    {
        int *skillsOfCurrentEmployee = employees[i];
        for (int j = 0; j < quantityOfEmployees; j++)
        {
            pii pairsOfEmployees;
            int *skillsOfEmployeeToCompare;
            if (i != j)
            {
                skillsOfEmployeeToCompare = employees[j];
                if (isAPossiblePair(skillsOfCurrentEmployee, skillsOfEmployeeToCompare, quantityOfSkills))
                {
                    pairsOfEmployees.first = i;
                    pairsOfEmployees.second = j;
                    pairs.pb(pairsOfEmployees);
                }
            }
        }
    }

    return pairs.size();
}

int main()
{
    int cases; //Between 1 - 20
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int quantityOfEmployees = 0;
        int quantityOfSkills = 0;
        cin >> quantityOfEmployees;
        cin >> quantityOfSkills;
        vector<int *> employees;
        for (int p = 0; p < quantityOfEmployees; p++)
        {
            int *skillsAndQuantity = new int[quantityOfSkills];
            for (int j = 0; j < quantityOfSkills; j++)
            {
                skillsAndQuantity[j] = 0;
            }
            int skills;
            cin >> skills;
            while (skills > 0)
            {
                int skillNumber;
                cin >> skillNumber;
                skillsAndQuantity[skillNumber - 1] = 1;
                skills--;
            }
            employees.pb(skillsAndQuantity);
        }

        int totalOfPairs = getTotalOfPairs(employees, quantityOfEmployees, quantityOfSkills);

        cout << "Case #" << i + 1 << ": " << totalOfPairs << endl;
    }
    return 0;
}