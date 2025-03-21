#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

int lis(vector<ll> a) {
    vector<ll> aux;
    for (auto num : a) {
        auto it = lower_bound(aux.begin(), aux.end(), num);
        if (it == aux.end()) aux.push_back(num);
        else *it = num;
    }

    return aux.size();
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << lis(a) << endl;
}