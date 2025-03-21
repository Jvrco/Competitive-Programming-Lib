#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

int seg_n;
vector<ll> segtree;

void build(int node, int start, int end, const vector<ll> &arr) {
    if(start == end) {
        segtree[node] = arr[start];
    }
    else {
        int m = (start + end) / 2;
        build(2*node+1, start, m, arr);
        build(2*node+2, m+1, end, arr);
        segtree[node] = segtree[2*node+1] + segtree[2*node+2];
    }
}

ll query_func(int node, int start, int end, int l, int r) {
    if(r < start || end < l)
        return 0;
    if(l <= start && end <= r)
        return segtree[node];
    int m = (start + end) / 2;
    ll son1 = query_func(2*node+1, start, m, l, r);
    ll son2 = query_func(2*node+2, m+1, end, l, r);
    return son1 + son2;
}

void update_func(int node, int start, int end, int pos, int val) {
    if(pos < start || pos > end)
        return;
    if(start == end) {
        segtree[node] += val;
        return;
    }
    int m = (start + end) / 2;
    if(pos <= m)
        update_func(2*node+1, start, m, pos, val);
    else
        update_func(2*node+2, m+1, end, pos, val);
    segtree[node] = segtree[2*node+1] + segtree[2*node+2];
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> salary(n);
    for (int i = 0; i < n; i++){
        cin >> salary[i];
    }
    
    vector<int> comp;
    for (int i = 0; i < n; i++){
        comp.push_back(salary[i]);
    }
    
    vector<tuple<char, int, int>> queries;
    for (int i = 0; i < q; i++){
        char type;
        cin >> type;
        if (type == '!'){
            int k, x;
            cin >> k >> x;
            queries.push_back({type, k - 1, x});
            comp.push_back(x);
        } 
        else if (type == '?'){
            int a, b;
            cin >> a >> b;
            queries.push_back({type, a, b});
            comp.push_back(a);
            comp.push_back(b);
        }
    }
    
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int num = comp.size();
    vector<ll> arr(num, 0);
    vector<int> curr(n);

    for (int i = 0; i < n; i++){
        int idx = lower_bound(comp.begin(), comp.end(), salary[i]) - comp.begin();
        curr[i] = idx;
        arr[idx]++;
    }
    
    seg_n = num;
    segtree.assign(4 * num, 0);
    build(0, 0, num - 1, arr);
    
    for (auto &query : queries) {
        auto[type,x,y] = query;
        if (type == '!') {
            int emp = x; 
            int newSalary = y;
            int newIdx = lower_bound(comp.begin(), comp.end(), newSalary) - comp.begin();

            update_func(0, 0, num - 1, curr[emp], -1);
            update_func(0, 0, num - 1, newIdx, 1);
            curr[emp] = newIdx;
        } 
        else if (type == '?') {
            int a = x; 
            int b = y;
            int l = lower_bound(comp.begin(), comp.end(), a) - comp.begin();
            int r = upper_bound(comp.begin(), comp.end(), b) - comp.begin() - 1;
            
            cout << query_func(0, 0, num - 1, l, r) << endl;
        }
    }
}