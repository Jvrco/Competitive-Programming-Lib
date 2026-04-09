#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'             
#define MOD 1000000007        
typedef long long ll;
 
const int MAXV = 200000;
const ll INF = LLONG_MAX;
 
bool visited[MAXV];   
vector<pair<ll, ll>> adj[MAXV];
 
ll n, q;
vector<ll> arr, seg;  
 
vector<ll> segSum;  
 
void build(ll node, ll start, ll end) {
    if (start == end) {
        seg[node] = 1;
    } else {
        ll mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}
 
void update(ll node, ll start, ll end, ll idx, ll v) {
    if (start == end) {
        seg[node] = v;          
    } else {
        ll mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, v);
        else update(2 * node + 1, mid + 1, end, idx, v);
        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
}
 
ll find(ll node, ll l, ll r, ll k) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (seg[2 * node] >= k)
        return find(2 * node, l, mid, k);
    else
        return find(2 * node + 1, mid + 1, r, k - seg[2 * node]);
}
 
ll rangesum(ll node, ll start, ll end, ll l, ll r) {
    if (r < start || l > end) return 0LL;                
    if (l <= start && end <= r) return seg[node];     
    ll mid = (start + end) / 2;
    return rangesum(2 * node, start, mid, l, r)
        + rangesum(2 * node + 1, mid + 1, end, l, r);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);              
 
    cin >> n;              
    arr.resize(n + 1);          
    seg.resize(4 * n);          
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];          
    }
 
    build(1, 1, n);             
    for(int i = 1;i<=n;i++){
        ll p;
        cin >> p;
        ll idx = find(1, 1, n, p);
        cout << arr[idx] << " ";
        update(1, 1, n, idx, 0);
    }
 
    return 0;
}
