#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
const int dx[] = {1,0,0,-1};
const int dy[] = {0,1,-1,0};
ll INF = 10000000000000000;
ll MOD = 1e9 + 7;
ll FORM_MOD = 1e9 + 6;

//calculate a**b**c mod 1e9+7

ll fexp(ll a, ll b, ll m) { 
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll reduceNumber(string s, ll m) { //reduce number from a string to a int mod m
    ll result = 0;
    for (char c : s) {
        int digit = c - '0';
        result = (result * 10 + digit) % m; 
    }
    return result;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll d = fexp(b, c, FORM_MOD);
    ll ans = fexp(a, d, MOD); 
    cout << ans << endl;
}