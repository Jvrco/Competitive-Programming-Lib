#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define pll pair<ll, ll>

//maximum sum of values that fit in a w space
//n <= 100, w <= 10e5

vector<vector<ll>> memo;
int n;

ll knapsack(pll items[], ll w, ll i){
    if (w == 0) return 0;
    if (i >= n) return 0;

    if (memo[w][i] != -1) return memo[w][i];

    ll sum = knapsack(items, w, i+1);
    if (items[i].first <= w) {
        sum = max(sum, items[i].second + knapsack(items, w-items[i].first, i+1));
    }

    return memo[w][i] = sum;
}

void solve(){
    int w;
    cin >> n >> w;
    memo.resize(w+1, vector<ll>(n, -1));
    pll items[n];
    for (int i=0; i<n; i++) {
        ll a,b;
        cin >> a >> b;
        items[i] = {a,b};
    }

    ll ans = knapsack(items, w, 0);
    
    cout << ans << endl;
}