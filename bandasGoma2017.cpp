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
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ

struct nodoBanda{
    int price;
    int initialRange;
    int finalRange;
};

bool compareBands(nodoBanda i1, nodoBanda i2) 
{ 
    return (i1.price < i2.price); 
} 

bool isValidPath(int acumLeftRange, int acumRightRange, int acumPrice, int maxPrice, int len ){
    return (acumLeftRange <= len && acumRightRange >= len) && acumPrice <= maxPrice;
}

int findMinPath(vector<nodoBanda> bandsByPrice, int maxToPay, int len){
    int returnValue = -1;

    int size = bandsByPrice.size();
    for(int i = 0; i < size; i++){
        nodoBanda currentNode = bandsByPrice[i];
        int acumPrice = 0;
        int acumLeft = 0;
        int acumRight = 0;

        for(int j = i; j < size; j++){
            nodoBanda node = bandsByPrice[j];
            acumPrice += node.price;
            acumLeft += node.initialRange;
            acumRight+= node.finalRange;

            if(!isValidPrice()){
                acumPrice = currentNode.price;
                acumLeft = currentNode.initialRange;
                acumRight = currentNode.finalRange;
            }
            else if(!isValidRange()){
                acumPrice -= node.price;
                acumLeft -= node.initialRange;
                acumRight -= node.finalRange;            
            }else{
                if(acumPrice <  returnValue){
                    returnValue = acumPrice;
                }
                //Missing case
            }
        }   
    
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    
    vector<nodoBanda> bandsByPrice;

    for(int i = 0; i < t; i++){
        int minPrice = -1;
        int quantityOfBands;
        int maxToPay;
        int len;
        cin >> quantityOfBands >> maxToPay >> len;

        while(quantityOfBands > 0){
            nodoBanda *node = new nodoBanda();
            cin >> node->initialRange >> node->finalRange >> node->price;
            bandsByPrice.pb(*node);
            quantityOfBands--;
        }
        sort(bandsByPrice.begin(),bandsByPrice.end(),compareBands);

        minPrice = findMinPath(bandsByPrice,maxToPay,len);

        if(minPrice == -1){
            cout << "Caso " << i <<": IMPOSIBLE" << endl;
        }else{
            cout << "Caso " << i << ": "<< minPrice <<endl;
        }
    }
    
    return 0;
}