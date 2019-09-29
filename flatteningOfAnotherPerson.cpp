#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <sstream>
#include <utility>
#include <map>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <functional>
#include <unordered_map>
#include <deque>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    k = min(k, n - 1);
    ++k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int>> p(1001, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 1001; ++j)
        {
            p[j][i + 1] = p[j][i];
        }
        p[a[i]][i + 1]++;
    }
    vector<vector<int>> sg(n, vector<int>(n, 0));
    for (int l = 0; l < n; ++l)
    {
        for (int r = l; r < n; ++r)
        {
            for (int j = 0; j < 1001; ++j)
            {
                sg[l][r] = max(sg[l][r], p[j][r + 1] - p[j][l]);
            }
            sg[l][r] = r - l + 1 - sg[l][r];
            //cerr << l << " " << r << " " << sg[l][r] << endl;
        }
    }
    vector<vector<int>> d(sg);
    for (int i = 1; i < k; ++i)
    {
        for (int l = 0; l < n; ++l)
        {
            for (int r = n - 1; r >= l + i; --r)
            {
                for (int tr = l; tr < r; ++tr)
                {
                    d[l][r] = min(d[l][r], d[l][tr] + sg[tr + 1][r]);
                }
            }
        }
    }
    cout << d[0][n - 1] << endl;
}

//#define LOCAL

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        cerr << tt << endl;
        cout << "Case #" << tt << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}