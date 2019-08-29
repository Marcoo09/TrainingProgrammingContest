/* 
//Author Santiago Topolansky
//Problem Street Checkers Kickstart 2019 Round E

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
#include <unordered_map>
#include <cassert>
using namespace std;
typedef pair<int, int> pii;
#define par first
#define imp second

pii divs(int xact, int x, pii acum, unordered_map <int, pii> &umap) {
	unordered_map<int, pii>::iterator it = umap.find(xact);
	if (xact == 1) {
		//Guardamos los valores acum hallados para x y retornamos.
		acum.imp++;
		umap[x] = acum;
		return acum;
	}

	if (it == umap.end()) {
		if (x%xact == 0) {
			if (xact % 2 == 0) acum.par++;
			else acum.imp++;
		}
		return divs(xact - 1, x, acum, umap);
	}
		//Si no encuentro optimizacion, calculo divisor
	else {
		//Sumo los valores que ya encontre para ese divisor antes.
		acum.par += it->second.par;
		acum.imp += it->second.imp;
		umap[x] = acum;
		return acum;
}
}

int main() {
	//Read T testCases
	int T;
	cin >> T;
	int* Larr = new int[T];
	int* Rarr = new int[T];
	for (int contT = 1; contT < T+1; contT++) {
		int L, R;
		cin >> L >> R;
		Larr[contT - 1] = L;
		Rarr[contT - 1] = R;
	}

	for (int contT = 1; contT < T + 1;contT++) {
		//Read L and R range
		int L, R;
		int contInt = 0;
		unordered_map <int, pii> opt;
		L = Larr[contT - 1];
		R = Rarr[contT - 1];
		//cin >> L >> R;
		//For each x between L and R:
			// If x esta en el hashmap, return el valor.
			// Else Calcular cantidad de divisores pares e impares de x, incluyendo al propio num y al 1.
			//		Agrego al hashmap la dupla para optimizacion
			// Si la dif de div pares - impares <=2, ++Contador casos interesantes.
		for (int i = L; i < R + 1; i++) {
			pii acum;
			acum.par = 0; acum.imp = 0;
			acum = divs(i, i, acum, opt);
			if (abs(acum.par - acum.imp) <= 2) {
				contInt++;
			}
		}
		cout << "Case #" << contT << ": " << contInt << endl;
	}
	return 0;
}*/

//After looking at the google's analysis, i re-wrote the algorithm for the first small test case and it was correctly admited. 

//Author Santiago Topolansky
//Problem Street Checkers Kickstart 2019 Round E. Looking at Solution

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
#include <unordered_map>
#include <cassert>
using namespace std;

bool interesting(int x) {
	int oddDivs = 0;
	int evenDivs = 0;
	for (int i = 1; i <= sqrt(x); i++) {
		if (x%i == 0) { //If i divides x, x/i and i are divisors
			if ((x / i) % 2 == 0) {//Clasificate x/i and i in even and odd
				evenDivs++;
			}
			else { oddDivs++; }

			if (x / i != i) {// Is x/i == i? Square root divisor. 
				if (i % 2 == 0) {
					evenDivs++;
				}
				else { oddDivs++; }
			}
		}
	}
	return (abs(evenDivs - oddDivs) <= 2);
}

int main() {
	int T;
	cin >> T;
	int* arr = new int[1000001];//Array of interesting cases (acum)
	arr[0] = 0;

	for (int x = 1; x < 1000001; x++) { // If interesting, ++ to previous position, else: previous position
		if (interesting(x)) { arr[x] = 1 + arr[x - 1]; }
		else { arr[x] = arr[x - 1]; }
	}

	for (int i = 1; i < T + 1; i++) {
		int L, R;
		cin >> L >> R;
		cout << "Case #" << i << ": " << (arr[R] - arr[L - 1]) << endl;

	}


	return 0;
}