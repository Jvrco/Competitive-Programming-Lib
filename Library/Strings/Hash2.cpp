#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
ll INF = 10000000000000000;
ll M = 999999900409;
ll N = 999999900637;
ll K = 1000213;

//A border of a string is a prefix that is also a suffix of the string but not the whole string. 
//For example, the borders of abcababcab are ab and abcab.

//Your task is to find all border lengths of a given string.

ll mod_mul(ll a, ll b, ll mod){
    __int128 t = a;
    t = t * b;
    t %= mod;
    return (ll)t;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    ll pref[n];
    ll powers[n+1];
    pref[0] = s[0] - 'a';
    powers[0] = 1;

    for (int i=1; i<n; i++) {
        pref[i] = (pref[i-1] * K + (s[i] - 'a')) % M;
    }

    for (int i=1; i<=n; i++) {
        powers[i] = (powers[i-1] * K) % M;
    }

    vector<ll> ans;
    ll prefHash;
    ll sufHash;
    for (int i=0; i<n-1; i++) {
        prefHash = pref[i];

        int l = n-1-i;
        int r = n-1;

        sufHash = pref[r] - mod_mul(pref[l-1], powers[r-l+1], M);
        sufHash = (sufHash % M + M) % M;

        if (prefHash == sufHash) ans.push_back(i+1);
    }

    for (int i=0; i<ans.size(); i++) {
        if (i != ans.size() - 1) cout << ans[i] << " ";
        else cout << ans[i] << endl;    
    }

}