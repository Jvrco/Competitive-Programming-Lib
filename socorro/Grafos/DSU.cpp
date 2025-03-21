#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef long long ll;
const int MAXV = 1e6;
const ll INF = LLONG_MAX;
bool visited[MAXV];   
vector<pair<int, ll>> adj[MAXV];


vector<int> p, sz;

void make_set(int v) {
    p[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == p[v]) return v;
    return p[v] = find_set(p[v]); 
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    p.resize(n+1);
    sz.resize(n+1);

    for(int i = 1;i<=n;i++){
        make_set(i);
    }

    for(int i = 0;i<m;i++){
        int x,y;
        cin >> x >> y;
        union_set(x,y);
    }

    vector<ll> count(n+1,0);
    for(int i = 1;i<=n;i++){
        count[find_set(i)]++;
    }

    ll ans = 1;

    for(int i = 1;i<=n;i++){
        if(count[i] > 0){
            ans = (ans * count[i]) % MOD;
        }
    }

    if(ans == 1){
        cout << (n % MOD) << endl;
    }
    else{
        cout << ans % MOD << endl;
    }
    return 0;

}