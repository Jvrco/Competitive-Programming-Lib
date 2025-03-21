#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAXV = 1e5 + 5;

vector<pair<int, int>> adj[MAXV]; 
int team[MAXV];                 

void bfs(ll n,  vector<vector<ll>>& adjr) {
    vector<ll> dist(n,-1);
    queue<ll> q;
    vector<bool> visited(n,false);

    ll t = n - 1;
    q.push(t);
    visited[t] = true;
    dist[t] = 0;

    while(!q.empty()){
        ll curr = q.front();
        q.pop();

        for(int i : adjr[curr]){
            if(dist[i] == -1){
                dist[i] = dist[curr] +1;
                q.push(i);
            }

           
        }
    }
    for(ll j : dist){
        cout << j << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("jumping.in", "r", stdin);
    ll cases;
    cin >> cases;
    while(cases--){
        ll n;
        cin >> n;
        vector<ll> d(n);
        for(int i = 0;i<n;i++){
            cin >> d[i];
        }
        vector<vector<ll>> adjr(n, vector<ll>());
        for(ll i=0;i<n;i++){
            if(i + d[i] <n){
                adjr[i +d[i]].push_back(i);
            }
            if(i - d[i] >=0){
                adjr[i -d[i]].push_back(i);
            }
        }



        bfs(n,adjr);

    }

    

    return 0;
}
