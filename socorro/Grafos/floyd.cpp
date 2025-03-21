#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXV = 500;
const ll INF = LLONG_MAX;
void fw(int n,vector<vector<ll>>& dist){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
    }



}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0; 
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;  
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);   
    }
    fw(n,dist);

    for(int i = 0;i<q;i++){
        int a,b;
        cin >> a >>b;
        if(dist[a][b]== INF){
            cout << -1 << endl;
            continue;
        }
        cout << dist[a][b] << endl;
    }
    return 0;
}
