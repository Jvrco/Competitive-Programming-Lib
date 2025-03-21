#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
ll INF = 10000000000000000;
ll M = 999999900409;
ll N = 999999900637;
ll K = 1000213;

//A period of a string is a prefix that can be used to generate the whole string by repeating the prefix. 
//The last repetition may be partial. For example, the periods of abcabca are abc, abcabc and abcabca.

//Your task is to find all period lengths of a string.

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
    ll nexHash;
    for (int i=0; i<n-1; i++) {
        prefHash = pref[i];
        bool ok = true;
        int l = i+1;
        int r = l+i;
        while (r<n && ok) {
            nexHash = pref[r] - mod_mul(pref[l-1], powers[r-l+1], M);
            nexHash = (nexHash % M + M) % M;
            if (prefHash != nexHash) ok = false;
            l = r+1;
            r = l+i;
        }
        int mod = i+1;
        int num = n % mod;
        if (num != 0 && ok) {
            prefHash = pref[num-1];
            l = n - num;
            r = n-1;
            nexHash = pref[r] - mod_mul(pref[l-1], powers[r-l+1], M);
            nexHash = (nexHash % M + M) % M;
        } 
        
        if (prefHash == nexHash) ans.push_back(i+1);
    }
    ans.push_back(n);

    for (int i=0; i<ans.size(); i++) {
        if (i != ans.size() - 1) cout << ans[i] << " ";
        else cout << ans[i] << endl;    
    }

}