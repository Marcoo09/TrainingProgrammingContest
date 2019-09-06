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

int maxArray(int levels[12]) {
	int max = -1;
	for (int i = 0; i < 11; i++) {
		if (levels[i] > 0)
			max = i;
	}
	return max;
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i < T+1; i++) {
		int* levels = new int[12]();//Array to count how many employees exist of that experience
		int* gestion= new int[12]();//Array to count boss capacity of all employees in that level
		int L;
		cin >> L; //Lines
		while (L > 0) {
			int N, E;
			cin >> N >> E;
			levels[E] = N;
			gestion[E] = N * E;
			levels[11] += N;//Total of Employees
			L--;
		}
/*
		for (int m = 0; m < 11; m++) {
			cout << "(" << levels[m] << ") ";
 		}
		*/
		int answer;
		/*For each level which has at least one employee, starting from 10,
		we go over each lower level, substracting from the G and of the N of that level
		for each employee that we find in that lower level. Once that there are no more levels to go through,
		the answer is the lowest int, bigger than the maxN, and which is bigger than
		the total of Ns left in all the levels*/
		int maxN = maxArray(levels);

		for (int j = 10; j > -1 && levels[11] > 1; j--) {//Start from level 10 and exit condition total > 1
			for (int k = j - 1; k > -1 && gestion[j] > 0; k--) {// if actual gestion > 0, iter down substracting 
				while (gestion[j] > 0 && levels[k] > 0) {
					levels[k]--;
					levels[11]--;
					gestion[j]--;
				}
			}
		}

		//Calculate answer
		int ans = maxN + 1;

		//if ans is lower than 10 and is still less than the total employees left to manage, ans++
		for (ans = maxN + 1; ans < 10 && ans < levels[11]; ans++) {
		}

		cout << "Case #" << i << ": " << ans << endl;



	}

	return 0;
}