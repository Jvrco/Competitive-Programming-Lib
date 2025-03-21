#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

bool solve(vector<ll>& arr,ll mid,ll c){
    ll n = arr.size();
    ll u = arr[0];
    ll contador = 1;
    for(int i = 1;i<n;i++){
        if(arr[i]-u >=mid){
            u = arr[i];
            contador+=1;
        }
    }
    if(contador>=c){
        return true;
    }
    else{
        return false;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    while(cases--){
        ll n,c;
        cin >> n >> c;
        vector<ll> arr(n);
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        ll l = 1;
        sort(arr.begin(),arr.end());
        ll r = arr[n-1] - arr[0];
        ll ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(solve(arr,mid,c)){
                ans = mid;
                l = mid +1;
            }
            else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}