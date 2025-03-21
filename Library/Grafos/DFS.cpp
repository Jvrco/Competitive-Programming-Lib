#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> grid;
string snuke = "snuke";
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<bool>> visited;

bool isValid(int x, int y, int step) {
    return x >= 0 && x < H && y >= 0 && y < W &&
           !visited[x][y] &&
           grid[x][y] == snuke[step % 5];
}

bool dfs() {
    stack<pair<pair<int, int>, int>> s;

    s.push({{0, 0}, 0});
    visited[0][0] = true;

    while (!s.empty()) {
        auto current = s.top();
        s.pop();

        int x = current.first.first;
        int y = current.first.second;
        int step = current.second;

        if (x == H - 1 && y == W - 1) {
            return true;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (isValid(nx, ny, step + 1)) {
                visited[nx][ny] = true;
                s.push({{nx, ny}, step + 1});
            }
        }
    }

    return false;
}

int main() {
    cin >> H >> W;
    grid.resize(H);
    visited.assign(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    if (dfs()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}