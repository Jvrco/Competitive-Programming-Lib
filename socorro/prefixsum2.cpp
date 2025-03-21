#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll MOD = 1000000007;
const int MAXV = 1e5 + 5;
const int MAXN = 200000;
vector<int> adj[MAXV];
vector<bool> visited(MAXV,false);
int n,m;
vector<int> seq;
vector<vector<int>> ans;
int solve(int i){
    int s = 0;
    while(i>0){
        s += i%10;
        i /=10;
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    ll prefix[MAXN+1];
    for(int i = 1;i<=MAXN;i++){
        prefix[i] = prefix[i-1] + solve(i);
    } 
    while(cases--){
        int maior;
        cin >> maior;
        cout << prefix[maior] << endl;

    }
    
    return 0;
}