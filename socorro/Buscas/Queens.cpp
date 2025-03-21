#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int contador = 0;
bool column[8] = {false};
bool diag1[15] = {false};
bool diag2[15] = {false};
vector<string> board(8);

void solve(int r){
    if(r == 8){
        contador++;
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (board[r][col] == '.' && !column[col] && !diag1[r + col] && !diag2[r - col + 7]) {
            column[col] = diag1[r + col] = diag2[r - col + 7] = true;
            solve(r + 1);
            column[col] = diag1[r + col] = diag2[r - col + 7] = false;
        }
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0;i<8;i++){
        cin >> board[i];
    }
    solve(0);
    cout << contador << endl;
    return 0;
}
