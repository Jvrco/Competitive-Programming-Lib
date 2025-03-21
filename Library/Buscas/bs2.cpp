#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n';

int isPos(int m, string s){
    return 1;
}
void solve() {
    string s;
    cin >> s;
    int l = 0;
    int r = s.size();
    int ans;
    while (r>=l) { //more common use of BinarySearch
        int m = (l+r)/2;
        if (isPos(m,s)) {
            ans = m;
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    cout << ans << endl;
}