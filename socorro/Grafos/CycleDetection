#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
const int dx[] = {1,0,0,-1};
const int dy[] = {0,1,-1,0};

int n,m;
vector<vector<int>> g;
vector<bool> vis;
vector<int> par;
vector<int> ans;

bool dfs(int u, int p) { //See with recursive dfs if there is a cycle of size >=3
    vis[u] = true;
    par[u] = p;
    for (int v: g[u]) {
        if (!vis[v]) {
            if (dfs(v,u)) return true;
        }
        else {
            if (par[u] != v) {
                ans.push_back(v);
                int x = u;
                while (x != v) {
                    ans.push_back(x);
                    x = par[x];
                }
                ans.push_back(x);
                return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1);
    par.resize(n+1);
    bool ok = false;
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            if (dfs(i,-1)) {
                ok = true;
                break;
            }
        }
    }

    if (!ok) cout << "IMPOSSIBLE" << endl;
    else {
        cout << ans.size() << endl;
        for (int i=ans.size()-1; i>=0; i--) {
            if (i != 0) cout << ans[i] << " ";
            else cout << ans[i] << endl;
        }   
    }

}
