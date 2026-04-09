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
vector<ll> arr, seg1,seg2;  
 
vector<ll> segSum;  
 
void build(ll node, ll start, ll end) {
    if (start == end) {
        seg1[node] = arr[start] + start; 
        seg2[node] = arr[start] - start; 
    } else {
        ll mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        seg1[node] = min(seg1[2 * node], seg1[2 * node + 1]);
        seg2[node] = min(seg2[2 * node], seg2[2 * node + 1]);
    }
}
 
void update(ll node, ll start, ll end, ll idx, ll v) {
    if (start == end) {
        arr[idx] = v;
        seg1[node] = arr[idx] + idx;
        seg2[node] = arr[idx] - idx;    
    } else {
        ll mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, v);
        else update(2 * node + 1, mid + 1, end, idx, v);
        seg1[node] = min(seg1[2 * node], seg1[2 * node + 1]);
        seg2[node] = min(seg2[2 * node], seg2[2 * node + 1]);
    }
}
 
 
ll query1(ll node, ll start, ll end, ll l, ll r) {
    if (r < start || l > end) return INF;
    if (l <= start && end <= r) return seg1[node];
    ll mid = (start + end) / 2;
    return min(query1(2 * node, start, mid, l, r),
               query1(2 * node + 1, mid + 1, end, l, r));
}
 
ll query2(ll node, ll start, ll end, ll l, ll r) {
    if (r < start || l > end) return INF;
    if (l <= start && end <= r) return seg2[node];
    ll mid = (start + end) / 2;
    return min(query2(2 * node, start, mid, l, r),
               query2(2 * node + 1, mid + 1, end, l, r));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);              
 
    cin >> n >> q;              
    arr.resize(n + 1);          
    seg1.resize(4 * n);   
    seg2.resize(4 * n);         
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];          
    }
 
    build(1, 1, n);             
    while(q--){
        ll a, b;
        cin >> a >> b;
        if(a == 1){
            int x;
            cin >> x;
            update(1, 1, n, b, x);
        }
        else{
        
            ll lans = query2(1, 1, n, 1, b) + b;
            ll rans = query1(1, 1, n, b, n) - b;
 
            cout << min(lans, rans) << endl;
        }
    }
 
    return 0;
}