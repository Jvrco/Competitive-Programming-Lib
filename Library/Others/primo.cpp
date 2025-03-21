#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
vector<vector<int>> adj;
vector<int> s;
vector<int> topos;
bool hs;
int const UNV = 0;
int const V = 1;
int const VI = 2;

bool prime(int x){
    if(x<2) return false;
    if(x%2 == 0 && x!=2) return false;
    for(int i = 3;i*i<=x;i+=2){
        if(x%i ==0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int x = 4;
        while(true){
            if(!prime(x) && prime(x+(n-1))) break;
            else{
                x++;
            }
        }
        vector<vector<int>> ans(n,vector<int>(n,1));
        for(int i = 0;i<n;i++){
            ans[i][i] = x;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout << ans[i][j];
                if(j!=n-1) cout << " ";
            }
            cout << endl;
        }

    }
    return 0;
}
