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
}