#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXV = 200000;
const ll INF = LLONG_MAX;
bool visited[MAXV];   
vector<pair<int, ll>> adj[MAXV];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
ll fact[61];



ll comb(ll n,ll k){
    if(k>n) return 0;
    if(k>n-k) k = n - k;
    ll ans = 1;
    for(int i = 0;i< k;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //fact[0] = 1;
    //for(int i = 1;i<= 60;i++){
    //    fact[i] = fact[i-1] * i;
    //}

    int n,m,t;
    cin >> n >> m >> t;
    ll ans = 0;
    ll s = max(4,t-m);
    ll e = min(n,t-1);
    for(int i = s;i<=e;i++){
        ans += comb(n,i) * comb(m,t-i);
    }

    cout << ans << endl;
    
    return 0;
}