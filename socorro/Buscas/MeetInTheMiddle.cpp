#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>

int n;
vector<ll> a; //works for n <= 40

void rec(int i, ll sum, vector<ll>& sums, vector<ll>& a) { 
    if (i == a.size()) {
        sums.push_back(sum);
        return;
    }

    rec(i + 1, sum + a[i], sums, a);

    rec(i + 1, sum, sums, a);
}

ll twoSum(vector<ll>& sub1, vector<ll>& sub2, ll k) {
    int i = 0;
    int j = sub2.size() - 1;
    ll count = 0;
    while (i < sub1.size() && j >= 0) {
        ll sum = sub1[i] + sub2[j];
        if (sum == k) {
            int start_i = i;
            while (i < sub1.size() && sub1[i] == sub1[start_i]) {
                i++;
            }
            int start_j = j;
            while (j >= 0 && sub2[j] == sub2[start_j]) {
                j--;
            }
            count += (ll)(i - start_i) * (start_j - j);
        } else if (sum < k) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}


void solve() {
    ll x;
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> sub1, sub2;

    int mid = n / 2;
    vector<ll> left(a.begin(), a.begin() + mid);
    vector<ll> right(a.begin() + mid, a.end());

    rec(0, 0, sub1, left);
    rec(0, 0, sub2, right);
    sort(sub1.begin(), sub1.end());
    sort(sub2.begin(), sub2.end());
    
    ll ans = twoSum(sub1, sub2, x);
    cout << ans << endl;
}