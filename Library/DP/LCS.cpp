#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MOD 1000000007
typedef long long ll;
const int MAXV = 1e5 + 5;
const ll INF = LLONG_MAX;

string s,t;
vector<vector<int>> dp;

int LCS(int i, int j){
    if(i == (int)s.size() || j == (int)t.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) return dp[i][j] = 1 + LCS(i+1, j+1);
    return dp[i][j] = max(LCS(i+1, j), LCS(i, j+1));
}

string r(int i, int j){
    if(i == s.size() || j == t.size()) return "";

    if(s[i] == t[j]){
        return s[i] + r(i+1, j+1);
    }

    if(LCS(i+1, j) >= LCS(i, j+1)){
        return r(i+1, j);
    }
    return r(i, j+1);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    dp.assign(s.size(), vector<int>(t.size(), -1));
    LCS(0,0);
    cout << r(0,0) << endl;
    
}
