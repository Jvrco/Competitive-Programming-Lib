#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXV = 1e5 + 5;
const ll INF = LLONG_MAX;
bool visited[MAXV];   
vector<pair<int, ll>> adj[MAXV];

void dij(int s,int n){
    vector<ll> dist(n+1,INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; 
    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty()){
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d>dist[u]) continue;

        for(auto &i : adj[u]){
            int v = i.first;
            ll w = i.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i = 1;i<n;i++){
        cout << dist[i] << " ";
    }
    cout << dist[n] << endl;


}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;  
        adj[a].push_back({b, c});  
    }
    dij(1,n);


    return 0;
}
