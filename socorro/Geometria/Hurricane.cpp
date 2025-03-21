#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
#define MOD 1000000007


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


double sqd(double x1, double y1, double x2, double y2, double x0, double y0){
    double dx = x2 - x1;
    double dy = y2 - y1;

    double cross = dx * (y0-y1) - dy * (x0-x1);

    double lensq = dx*dx + dy*dy;
    if(lensq == 0.0){
        return (x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1);
    }

    return (cross * cross)/ lensq;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    while(cases--){
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int m;
        cin >> m;
        vector<pair<string,pair<int,int>>> c(m);
        for(int i = 0;i<m;i++){
            string s;
            int cx, cy;
            cin >> s >> cx >> cy;
            c[i] = {s,{cx,cy}};
        }

        vector<double> distsq(m);
        for(int i = 0;i<m;i++){
            double cx = c[i].second.first;
            double cy = c[i].second.second;
            distsq[i] = sqd(x1,y1,x2,y2,cx,cy);
        }

        double mindist = *min_element(distsq.begin(),distsq.end());

        bool ok = false;
        for(int i = 0;i<m;i++){
            if(abs(distsq[i] - mindist) < 1e-15 ){
                if(ok) cout << " ";
                cout << c[i].first;
                ok = true;
            }
        }
        cout << endl;
    }
}
