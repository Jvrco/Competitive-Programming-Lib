#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXV = 1e5 + 5;
const ll INF = LLONG_MAX;

vector<ll> dij(ll n,ll s,  vector<vector<pair<ll, ll>>> &adj){
    vector<vector<ll>> dist(n + 1, vector<ll>(3, INF));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;

    dist[s][0] = 0;
    pq.push({0,s,0});
    vector<vector<bool>> visited(n + 1, vector<bool>(3, false));

    while(!pq.empty()){
        auto[curr,u,r] = pq.top();
        pq.pop();
        if(curr>dist[u][r]) continue;

        

        if(u == n) continue;
        for(auto &[v,w] : adj[u]){
            ll nr = (r+1) % 3;
            ll nc = curr + w;

            if(nc < dist[v][nr]){
                dist[v][nr] = nc;
                pq.push({nc,v,nr});
            }
        }
    }
    
    vector<ll> ans;
    ans.push_back(dist[n][0]);	
    ans.push_back(dist[n][1]);	
    ans.push_back(dist[n][2]);	
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll a, b;
        ll c;
        cin >> a >> b >> c;  
        adj[a].push_back({b, c});  
        adj[b].push_back({a, c});  

    }
    vector<ll> ans = dij(n,1,adj);

    vector<string> s = {"me","Gon","Killua"};
    vector<pair<ll, string>> ansf;
    
    for(int i = 0;i<3;i++){
       
        ansf.push_back({ans[i],s[i]});
        
       
    }

    sort(ansf.begin(),ansf.end());

    cout << ansf[0].second << endl;
    cout << ansf[1].second << endl;
    cout << ansf[2].second << endl;


    return 0;
}
