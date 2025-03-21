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
        ll x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll ans = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

        if(ans > 0) cout << "LEFT" << endl;
        else if(ans<0) cout << "RIGHT" << endl;
        else{
            cout << "TOUCH" << endl;
        }
    }
    return 0;
}
