#include <iostream>
//#include <stdio.h>
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
#include <unordered_map>
#include <cassert>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int j = 1; j < T+1;j++) {
		//Case Starts
		int lineas;
		cin >> lineas;
		cin.ignore();
		int* arr = new int[1];
		int arrsize = 0;
		for (int i = 0; i < lineas; i++) {
			//Reads all the line and then separates each int from it
			string line;
			getline(cin, line);
			istringstream is(line);
			int n;
			int pos = 0;

			//First line, calculate line length and create array that long
			if (i == 0) {
				istringstream is2(line);
				while (is2 >> n) {
					arrsize = arrsize + n;
				}
				arr = new int[arrsize + 1];
				//Initialize array in 0s
				for (int n = 0; n < arrsize + 1; n++) {
					arr[n] = 0;
				}
			}

			while (is >> n) {//Calculate joints of bricks and sum 1 to the array in those positions
				pos = pos + n;
				arr[pos]++;
			}
		}
		
		int max = 0;
		for (int i = 1; i < arrsize-1; i++) {
			if (max < arr[i]) {
				max = arr[i];
			}
		}

		//Answer, Number of Lines - max;
		cout << "Caso " << j << ": " << lineas - max <<endl;
		
		//It is missing to initialize all the ints of the array in 0;
	}
	return 0;
}