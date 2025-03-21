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

bool solve(int a,int b, int c, int d){
    return (a<c && c<b && b < d) || (c<a && a<d && d<b);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> ch(m);
    for(int i = 0;i<m;i++){
        cin >> ch[i].first >> ch[i].second;
        if(ch[i].first > ch[i].second){
            int aux = ch[i].first;
            ch[i].first = ch[i].second;
            ch[i].second = aux;
        }
        
    }
    vector<vector<int>> adj(m);
    for(int i = 0;i<m;i++){
        for(int j = i+1;j<m;j++){
            int a = ch[i]. first;
            int b = ch[i].second;
            int c = ch[j].first;
            int d = ch[j].second;
            if(solve(a,b,c,d)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(m,-1);

    for(int i = 0;i<m;i++){
        if(color[i] == -1){
            color[i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : adj[u]){
                    if(color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]){
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    for(int i = 0;i<m;i++){
        if(color[i] == 0) cout << 'i';
        else{
            cout << 'o';
        }
    }
    cout << endl;


    return 0;
}