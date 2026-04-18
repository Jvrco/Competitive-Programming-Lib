#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

const int MAXV = 200000;
const ll INF = LLONG_MAX;

bool visited[MAXV];
vector<pair<int, ll>> adj[MAXV];

int n, q;
vector<ll> arr, seg, lazy;

void build(int node, int start, int end) {
    lazy[node] = 0;
    if (start == end) {
        seg[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

void push(int node, int start, int end) {
    if (lazy[node] == 0) return;

    seg[node] += lazy[node];

    if (start != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, ll val) {
    push(node, start, end);

    if (r < start || end < l) return;

    if (l <= start && end <= r) {
        lazy[node] += val;
        push(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);

    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

ll rangem(int node, int start, int end, int l, int r) {
    push(node, start, end);

    if (r < start || end < l) return INF;

    if (l <= start && end <= r) return seg[node];

    int mid = (start + end) / 2;
    ll lm = rangem(2 * node, start, mid, l, r);
    ll rm = rangem(2 * node + 1, mid + 1, end, l, r);

    return min(lm, rm);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    arr.resize(n + 1);
    seg.resize(4 * n + 5);
    lazy.resize(4 * n + 5, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, b;
            ll val;
            cin >> a >> b >> val;
            update(1, 1, n, a, b, val);
        } else {
            int a, b;
            cin >> a >> b;
            cout << rangem(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
