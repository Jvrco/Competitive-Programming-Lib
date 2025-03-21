#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
ll INF = 1e18;

vector<ll> dp;
vector<ll> path;
int n,k;

ll pathDp(int i){
    if (i == 0) return dp[i] = 0;
    
    if (dp[i] != INF) return dp[i];
    for (int j=1; j<=k; j++) {
        if (j <= i) dp[i] = min(dp[i], abs(path[i] - path[i-j]) + pathDp(i-j));
    }

    return dp[i];
}


void solve(){
    cin >> n >> k;
    dp.resize(n,INF);
    path.resize(n);
    for (int i=0; i<n; i++) {
        cin >> path[i];
    }

    ll ans = pathDp(n-1);
    
    cout << ans << endl;
}