#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXV = 1e6 + 5;
const ll INF = LLONG_MAX;

ll modxp(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    ll maxval = n+m;

    vector<ll> fact(maxval + 1), invfact(maxval+1);

    fact[0] = 1;
    for(ll i = 1;i<=maxval;i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invfact[maxval] = modxp(fact[maxval],MOD-2,MOD);

    for(ll i = maxval - 1;i>=0;i--){
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }

    ll a = n + m -1;
    ll b = m;
    ll ans = fact[a];
    ans = (((ans * invfact[b]) % MOD) * invfact[a-b]) % MOD;
    cout << ans << endl;
    return 0;
}
