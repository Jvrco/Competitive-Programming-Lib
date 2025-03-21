#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

//Your task is to count the number of integers between a and b where no two adjacent digits are the same.

ll a,b;
ll dp[20][10][2][2];

ll solveDp(string num, int n, int x, bool zeros, bool tight) {
    if (n == 0) return 1;
    if (x != -1 && dp[n][x][zeros][tight] != -1) return dp[n][x][zeros][tight];


    ll res = 0;
    int limit = tight ? (num[num.size() - n] - '0') : 9;
    for (int i=0; i<=limit; i++) {
        if (i == x && !zeros) continue;
        res += solveDp(num, n-1, i, zeros & (i == 0), tight & (i == limit));
    }
    return dp[n][x][zeros][tight] = res;
}

void solve() {
    cin >> a >> b;
    string A = to_string(a-1);
    string B = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll ans1 = solveDp(A, A.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = solveDp(B, B.size(), -1, 1, 1);

    cout << ans2 - ans1 << endl;
}