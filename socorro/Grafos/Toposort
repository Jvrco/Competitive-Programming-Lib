#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>

void solve(){ //O(n+m)
    int n,m;
    cin >> n >> m;
    vector<int> degree(n+1,0);
    vector<vector<int>> g(n+1);
    vector<int> ans;
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        degree[b]++;
    }

    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int v : g[u]) { 
            degree[v]--;
            if (degree[v] == 0) q.push(v);
        }
    }

    if (ans.size() < n) cout << "IMPOSSIBLE";
    else {
        for (int i=0; i<n; i++) {
            if (i == n-1) cout << ans[i] << endl;
            else cout << ans[i] << " ";
        }
    }
}
