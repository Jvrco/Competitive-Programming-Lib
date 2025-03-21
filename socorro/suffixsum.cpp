#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXV = 1e6 + 5;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0;i<n;i++){
            cin >> arr[i]; 
        } 
        vector<ll> suffix(n);
        suffix[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + arr[i];
           
        }
        ll ans = suffix[0];
        for(int i = 1;i<n;i++){
            //cout << suffix[i] << endl;
            ans += max(suffix[i],(ll)0);
        }
        cout << ans << endl;
    }
    return 0;
}
