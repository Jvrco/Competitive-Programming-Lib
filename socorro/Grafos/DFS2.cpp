#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXV = 1e5 + 5;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
ll start = -1, endi = -1;
bool visited[MAXV], sexo[MAXV];
ll parent[MAXV];
bool dfs(int u,vector<vector<ll>>& adj) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            sexo[v] = !sexo[u];
            if (!dfs(v,adj)) return false;
        } 
        else {
            if(sexo[v] == sexo[u]){
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    int contador = 0;
    
    while(cases--){ 
        

        ll n,m;
        cin >> n >> m;
        contador++;
        vector<vector<ll>> adj(n+1,vector<ll>());

        for(int i = 0;i<m;i++){
            ll a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        memset(visited,false,sizeof(visited));
        memset(sexo,false,sizeof(sexo));
        bool ok = true;
        for(int i = 1;i<=n;i++){
            if(!visited[i]){

                if(dfs(i,adj) == false){
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            cout << "Scenario #" << contador << ':' << endl;
            cout << "No suspicious bugs found!" << endl;
        }
        else{
            cout << "Scenario #" << contador << ':' << endl;
            cout << "Suspicious bugs found!" << endl;
        }
        

    }
    return 0;
}