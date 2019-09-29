#include <bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int ar[MAX_SIZE], n, k;
int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int rek(int cur, int kUsed, int changed)
{
    if (cur == n)
        return kUsed > k ? n : 0;
    if (dp[cur][kUsed][changed] == -1)
    {
        int rez = rek(cur + 1, kUsed + (cur - 1 - changed >= 0 && ar[cur] != ar[cur - 1 - changed]), 0);
        rez = min(rez, 1 + rek(cur + 1, kUsed, changed + 1));
        dp[cur][kUsed][changed] = rez;
    }
    return dp[cur][kUsed][changed];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, T;

    cin >> T;
    t = T;

    while (t--)
    {
        cin >> n >> k;
        for (int ctr1 = 0; ctr1 < n; ++ctr1)
            cin >> ar[ctr1];
        memset(dp, -1, sizeof(dp));
        cout << "Case #" << T - t << ": " << rek(0, 0, 0) << "\n";
    }
    return 0;
}