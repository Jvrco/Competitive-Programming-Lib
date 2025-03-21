#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXV = 1e5 + 5;
const ll INF = LLONG_MAX;
vector<pair<int, ll>> adj[MAXV];

void dij(int s,int n){
    vector<vector<ll>> dist(n+1,vector<ll>(2,INF));
    priority_queue<tuple<ll, int,bool>, vector<tuple<ll, int,bool>>, greater<tuple<ll, int,bool>>> pq; 
    dist[s][0] = 0;
    pq.push({0,s,false});

    while(!pq.empty()){
        auto[d,u,used] = pq.top();
        pq.pop();

        if(d>dist[u][used]) continue;

        for(auto &i : adj[u]){
            int v = i.first;
            ll w = i.second;
            if(dist[u][used] + w < dist[v][used]){
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used],v,used});
            }
            if(!used && dist[u][used] + w/2 < dist[v][1]){
                dist[v][1] = dist[u][used] + w /2;
                pq.push({dist[v][1],v,true});
            }
        }
    }

    cout << dist[n][1] << endl;

   
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
