#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

int n;
vector<vector<int>> g;
vector<bool> vis;

int checkDist(int n, vector<int>& dist_vec){
    queue<int> q;
    vis[n] = true;
    q.push(n);
    int new_v = n;
    int dist = 1;
    dist_vec[n] = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int u = q.front();
            q.pop();

            for (int v: g[u]) {
                if (!vis[v]) {
                    q.push(v);
                    new_v = v;
                    dist_vec[v] = dist;
                    vis[v] = true;
                }
            }
        }
        dist++;
    }
    return new_v;
}

void solve(){
    int n;
    cin >> n;
    g.resize(n+1);;
    vis.resize(n+1, false);
    queue<int> q;
    for (int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis[1] = true;
    q.push(1);
    int v1 = 1;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            int u = q.front();
            q.pop();

            for (int v: g[u]) {
                if (!vis[v]) {
                    q.push(v);
                    v1 = v;
                    vis[v] = true;
                }
            }
        }
    }

    vector<int> dist1(n+1);
    fill(vis.begin(), vis.end(), false);
    int v2 = checkDist(v1,dist1);

    vector<int> dist2(n+1);
    fill(vis.begin(), vis.end(), false);
    checkDist(v2,dist2);

    for (int v=1; v<=n; v++) {
        if (v == n) cout << max(dist1[v],dist2[v]) << endl;
        else cout << max(dist1[v],dist2[v]) << " ";
    }
}
