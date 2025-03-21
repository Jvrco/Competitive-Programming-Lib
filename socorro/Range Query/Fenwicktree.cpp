#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef long long ll;
const int MAXV = 200000;
const ll INF = LLONG_MAX;
bool visited[MAXV];   
vector<pair<int, ll>> adj[MAXV];

ll tree[MAXV + 1]; 
int arr[MAXV + 1]; 
int n, q; 

void update(int idx,ll val){
    while(idx<= n){
        tree[idx] += val;
        idx += idx & -idx;
    }
}

ll prefixs(int idx){
    ll sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

ll rangesum(int a,int b){
    return prefixs(b) - prefixs(a-1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;

    for(int i = 1;i<=n;i++){
        cin >> arr[i];
        update(i,arr[i]);
    }

    while(q--){
        int t,a,b;
        cin >> t >> a >> b;

        if(t==1){
            update(a,b-arr[a]);
            arr[a] = b;
        } else if(t == 2){
            cout << rangesum(a,b) << endl;
        }
    }



    return 0;

}