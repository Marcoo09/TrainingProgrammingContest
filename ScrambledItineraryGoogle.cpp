//Scrambled Itinerary Google Kickstart 2018 Preparation Round
//https://code.google.com/codejam/contest/6214486/dashboard#s=p2

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
 
#define hashMapSS unordered_map<string,string>
#define hashMapSI unordered_map<string,int>

// Given a scrambled list of plane tickets (origin and destiny of each),
// return a sorted itinerary with the tickets ordered
// Solution: 
// 1) Find out starting location
// 2) Fly from city to city using tickets until final location is reached. Print the ticket each time it is used
string findOrigin(hashMapSI& timesVisited, hashMapSS& hashFromTo) {
	for (auto x : hashFromTo) //Travers the hashmap and returns the destiny which is never visited. That is the origin.
		if (timesVisited.find(x.first)==timesVisited.end()) return x.first;
	return "";
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i < T + 1; i++) {
		int N;
		cin >> N;
		hashMapSS hashFromTo;
		hashMapSI timesVisited;
		while (N > 0) { //Load Arrays
			string orig,dest;
			cin >> orig;
			cin >> dest;
			hashFromTo[orig] = dest;
			timesVisited[dest] = 1;
			N--;
		}

		cout << "Case #" << i << ": ";
		string current = findOrigin(timesVisited,hashFromTo);
		hashMapSS::iterator itr; //Define iterator to look into the hashmap
		itr = hashFromTo.find(current);
		while (itr != hashFromTo.end()) {
			cout << current << "-" << itr->second << " "; 
			current = itr->second;
			itr = hashFromTo.find(current);//Searchs if the next airport is origin in any ticket
		}
		cout << endl;
	}
	return 0;
}