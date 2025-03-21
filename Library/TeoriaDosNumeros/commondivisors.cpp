#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

void solve() {
    int n;
    cin >> n;
    int a[n];
    int ub = 0;
    int ans = 1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ub = max(ub,a[i]);
    }

    vector<int> b(ub+1,0);
    for (int i=0; i<n; i++) {
        b[a[i]]++;
    }

    for (int i=ub; i>=2; i--) {
        int count = 0;
        for (int j=i; j<=ub; j+=i) {
            if (b[j] != 0) count += b[j];
        }
        if (count > 1) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}