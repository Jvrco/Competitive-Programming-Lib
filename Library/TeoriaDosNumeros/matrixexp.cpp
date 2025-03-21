#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
ll MOD = 1e9 + 7;

//used to calculate fibonacci

const int m = 2;

class Matrix{
    public:
    ll mat[m][m] = {{1, 1}, {1, 0}};
    Matrix operator * (const Matrix &p){
        Matrix ans;
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                for (int k = ans.mat[i][j] = 0; k<m; k++) {
                    ans.mat[i][j] = (ans.mat[i][j] + 1LL * (mat[i][k] % MOD) * (p.mat[k][j] % MOD)) % MOD;
                }
            }
        }
        return ans;
    }

};

Matrix fexp(Matrix a, ll b) {
    Matrix ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ans.mat[i][j] = (i == j);
        }
    }

    while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }

    return ans;
} 

void solve() {
    ll n;
    cin >> n;
    Matrix a;
    Matrix b;
    a = fexp(b,n+1);
    ll ans = a.mat[1][1];
    cout << ans << endl;
}