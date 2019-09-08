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
//Flow Layout ORT 2018 
int main() {
	int WidthLimit;
	do {
			int insx, insy;
			int maxX = 0;
			int maxY = 0;
			cin >> WidthLimit;
			if (WidthLimit != 0) {
			int lastX = 0;//Column in which im inserting the blocks. Updates in every insert. 
			int lastY = 0;//Line in which i am inserting the blocks. Updates when changing line
			do {
				cin >> insx >> insy;
				if (insx != -1) {

					if ((insx + lastX) > WidthLimit) {//If the x to insert is bigger than maxWidth
						lastX = 0;
						lastY = maxY;//Bottom y becomes the maxy of the previous line
					}
					lastX += insx;
					if (lastX > maxX) maxX = lastX;//Update max x
					if (insy + lastY > maxY) maxY = insy + lastY;//Update max y		
				}
			} while (insx != -1);
			cout << maxX << " x " << maxY << endl;
		}
	} while (WidthLimit != 0);
	return 0;
}