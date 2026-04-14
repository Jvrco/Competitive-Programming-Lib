#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int H, W, N;
vector<ll> val;
ll ans = 0;

void rec(int mask, ll xr) {
    if (mask == (1 << N) - 1) {
        ans = max(ans, xr);
        return;
    }

    int p = 0;
    while (mask & (1 << p)) p++;

    rec(mask | (1 << p), xr ^ val[p]);

    int r = p / W;
    int c = p % W;

    if (c + 1 < W) {
        int q = p + 1;
        if (!(mask & (1 << q))) {
            rec(mask | (1 << p) | (1 << q), xr);
        }
    }

    if (r + 1 < H) {
        int q = p + W;
        if (!(mask & (1 << q))) {
            rec(mask | (1 << p) | (1 << q), xr);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    N = H * W;
    val.resize(N);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> val[i * W + j];
        }
    }

    rec(0, 0);

    cout << ans << '\n';
    return 0;
}