#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

//min number of coins to get a sum x; 

void solve(){
    vector<ll> dp; 
    int n,x;
    cin >> n >> x;
    ll coins[n];
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }
    dp.resize(x+1, -1);
    dp[0] = 0;
    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (coins[j] <= i && dp[i-coins[j]] != -1) {
                if (dp[i] != -1) dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                else  dp[i] = 1 + dp[i-coins[j]];
            }
        }
    }
    
    cout << dp[x] << endl;
}