#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

void solve() {
    int n,q;
    cin >> n;
    ll a[n];
    for (int i=0; i<n; i++) {
            cin >> a[i];
    }
    sort(a,a+n);
    cin >> q;
    
    while (q--) {
            ll x;
            ll ans;
            cin >> x;

            int l = -1;
            int r = n;
            while (r > l+1) { //how many in the array are <= x
                int m = (l+r)/2;
                if (a[m] <= x) {
                    l = m;
                }
                else {
                    r = m;
                }
            }

            ans = l+1;
            cout << ans << endl;
    }
}