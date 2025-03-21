#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define MOD 1000000007


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        unordered_set<ll> s0,s1;

        for(int i = 0;i<n;i++){
            ll x,y;
            cin >> x >> y;
            if(y == 0) s0.insert(x);
            else s1.insert(x);
        }

        ll a = s0.size();
        ll b = s1.size();

        ll contador = 0;

        if( a < b){
            for(auto &x : s0){
                if(s1.count(x)){
                    contador++;
                }
            }
        }
        else{
            for(auto &x : s1){
                if(s0.count(x)) contador++;
            }
        }

        ll vh = 0;
        if(contador > 0 && a >=1 && b >=1) vh = contador * ((a-1) + (b-1));

        ll d = 0;

        for(auto &x : s0){
            if(s1.count(x-1) && s1.count(x+1)){
                d++;
            }
        }

        for(auto &x : s1){
            if(s0.count(x-1) && s0.count(x+1)){
                d++;
            }
        }

        cout << (vh + d) << endl;
    }
}
