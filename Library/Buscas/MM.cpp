#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

int n;
ll m;
vector<ll> a;

void rec(int i, ll sum, vector<ll>& sums, vector<ll>& part) {
    if (i == (int)part.size()) {
        sums.push_back(sum);
        return;
    }

    rec(i + 1, sum, sums, part);
    rec(i + 1, (sum + part[i]) % m, sums, part);
}

void solve() {
    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    int mid = n / 2;
    vector<ll> left(a.begin(), a.begin() + mid);
    vector<ll> right(a.begin() + mid, a.end());

    vector<ll> sub1, sub2;
    rec(0, 0, sub1, left);
    rec(0, 0, sub2, right);

    sort(sub2.begin(), sub2.end());

    ll ans = 0;

    for (ll x : sub1) {
        ll target = m - x;

        auto it = lower_bound(sub2.begin(), sub2.end(), target);

        if (it != sub2.begin()) {
            --it;
            ans = max(ans, (x + *it) % m);
        }

        
        ans = max(ans, x);
    }

    cout << ans << endll;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}