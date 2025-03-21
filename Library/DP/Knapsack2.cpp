#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

// n,w <= 2e5

void solve(){
    int n, w;
    cin >> n >> w;
    vector<ll> dp(w+1,0);
    map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        ll v;
        string s;
        cin >> s >> v;
        int sz = s.size();
        if (m.find(sz) == m.end() || m[sz] < v) {
            m[sz] = v;
        }
    }

    vector<ll> bytes;
    vector<ll> value;
    for (auto [b, v]: m) {
        bytes.push_back(b);
        value.push_back(v);
    }

    for (int i=1; i<=w; i++) {
        for (int j=0; j<bytes.size(); j++) {
            if (bytes[j] <= i) {
                dp[i] = max(dp[i], dp[i-bytes[j]] + value[j]);
            }
        }
    }

    cout << dp[w] << endl;
}