#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
ll MOD = 1e9 + 7;

//paths that do not traverse a *

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    bool line = true;
    bool column = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
            if (i==0) {
                if (grid[i][j] == '*') line = false;
                else if (line) dp[i][j] = 1; 
            }
            if (j==0) {
                if (grid[i][j] == '*') column = false;
                else if (column) dp[i][j] = 1; 
            }
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (grid[i][j] != '*') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            } 
        }
    }
    cout << dp[n-1][n-1] << endl; 
}