#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAXV = 1000;
vector<string> grid;
bool visited[MAXV][MAXV];
int n, m, sx,sy,ex,ey;

vector<int> dx = {0, 0, -1, 1}; 
vector<int> dy = {-1, 1, 0, 0};
vector<char> dir  = {'L', 'R', 'U', 'D'};

map<pair<int, int>, pair<pair<int, int>, char>> parent;

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()){
        auto [cx,cy] = q.front();
        q.pop();
        
        if(cx == ex && cy == ey) return;

        for(int i = 0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                parent[{nx, ny}] = {{cx, cy}, dir[i]};
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(visited, false, sizeof(visited));
    
    cin >> n >> m;
    string x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        grid.push_back(x);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if (grid[i][j] == 'A') sx = i, sy = j;
            if (grid[i][j] == 'B') ex = i, ey = j;
        }
    }
    memset(visited, false, sizeof(visited));
    
    bfs(sx,sy);

    if(visited[ex][ey]){
        cout << "YES" << endl;

        string ans;
        pair<int,int> curr = {ex,ey};
        while(curr != make_pair(sx,sy)){
            ans += parent[curr].second;
            curr = parent[curr].first;
        }

        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    
    
    return 0;
}