#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
ll INF = 1e18;

//remove digits until get to 0

void solve(){ 
    vector<ll> dp;
    int n;
    cin >> n;
    dp.resize(n+1, INF);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        string s = to_string(i);
        for (char c: s) {
            int j = c - '0';
            if (j<=i) {
                dp[i] = min(dp[i], dp[i-j] + 1);
            }
        }
    }
    
    cout << dp[n] << endl;
}