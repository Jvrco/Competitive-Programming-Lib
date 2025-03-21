#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXV = 200000;
const ll INF = LLONG_MAX;
bool visited[MAXV];   
vector<pair<int, ll>> adj[MAXV];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
ll fact[61];
int n;
int sk[15][15];
ll ans = 0;
void dfs(int idx,ll cs,vector<bool> & used){
    if(idx == n){
        ans = max(cs,ans);
        return;
    }
    for(int j = 0;j<n;j++){
        if(!used[j]){
            used[j] = true;
            dfs(idx+1,cs + sk[idx][j],used);
            used[j] = false;
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    //sk.assign(n,vector<ll>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> sk[i][j];
        }
    }
    vector<bool> used(n,false);
    dfs(0,0,used);
    cout << ans << endl;
    
    return 0;
}