#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll MAXN = LLONG_MAX;

int solve(int n,ll contador, vector<int>& a,ll m){
    double nc = (double)(contador + m)/(2.0*n);
    if(nc > a[n/2]) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> a(n);
        ll contador = 0;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            contador += a[i];
        } 
        sort(a.begin(),a.end());
        int r = 1e7;
        int l = 0;
        ll ans = -1;
        while(l<=r){
            ll m = l + (r-l)/2;
            if(solve(n,contador,a,m)){
                ans = m;
                r = m -1;
            }
            else{
                l = m + 1;
            }
        }
        if(n == 1 || n == 2){
            ans = -1;
        }
        cout << ans << endl;

    }
    return 0;
}
