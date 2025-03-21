#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef long long ll;
const int MAXV = 200000;
const ll INF = LLONG_MAX;
bool visited[MAXV];   
vector<pair<int, ll>> adj[MAXV];

int n,q;
vector<int> arr,seg;

void build(int node,int start,int end){
    if (start == end) {
        seg[node] = arr[start]; 
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    }
}

void update(int node, int start, int end, int idx, int v){
    if (start == end) {
        arr[idx] = v; 
        seg[node] = v; 
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, v);
        else
            update(2 * node + 1, mid + 1, end, idx, v);
        
        seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    }
}

int rangem(int node, int start, int end, int l, int r) {
    if (r < start || l > end) return INT_MAX; 
    if (l <= start && end <= r) return seg[node]; 

    int mid = (start + end) / 2;
    int lm = rangem(2 * node, start, mid, l, r);
    int rm = rangem(2 * node + 1, mid + 1, end, l, r);
    
    return min(lm, rm);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    arr.resize(n+1);
    seg.resize(4*n);
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    build(1,1,n);
    while(q--){
        int t,a,b;
        cin >> t >> a >> b;
        if(t == 1) update(1,1,n,a,b);
        else if(t == 2) cout << rangem(1,1,n,a,b) << endl;
    }


    return 0;

}