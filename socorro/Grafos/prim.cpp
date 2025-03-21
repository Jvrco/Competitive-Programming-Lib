#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXV = 1e5 + 5;
const ll INF = LLONG_MAX;
vector<pair<int, ll>> adj[MAXV];

ll prim(ll n){
    vector<bool> visited(n+1,false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; 
    ll custo = 0;
    pq.push({0,n});
    ll contador = 0;
    while(!pq.empty()){
        ll w = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;
        custo += w;
        contador++;

        for (auto i : adj[u]) {
            ll v = i.first;
            ll c = i.second;
            if (!visited[v]) {
                pq.push({c, v});
            }
        }
    }
    if(contador < n){
        return -1;
    }
    return custo;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        ll c;
        cin >> a >> b >> c;  
        adj[a].push_back({b, c});  
        adj[b].push_back({a,c});
    }
    ll ans = prim(n);

    if(ans == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << ans << endl;
    }

    return 0;
}
