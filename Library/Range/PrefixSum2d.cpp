#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

vector<vector<int>> val;
vector<vector<int>> pref;

int query(int x1, int y1, int x2, int y2){
    int total = pref[x2][y2];
    int removeline = pref[x2][y1-1];
    int removecolumn = pref[x1-1][y2];
    int addexcedent = pref[x1-1][y1-1];
    return total - removeline - removecolumn + addexcedent;
}

void solve(){
    int n,q;
    cin >> n >> q;
    val.resize(n+1, vector<int>(n+1,0));
    pref.resize(n+1, vector<int>(n+1));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c ==  '*') val[i][j] = 1;
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            pref[i][j] = val[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]; 
        }
    }

    while(q--) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1,y1,x2,y2) << endl;
    }    
}
