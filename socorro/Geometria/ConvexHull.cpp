#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>
ll INF = 1e18;

struct pt{
    ll x,y;
    pt(ll x = 0, ll y = 0) : x(x), y(y){}

    pt operator+(pt o) const {
        return pt(x + o.x, y + o.y);
    }

    pt operator-(pt o) const {
        return pt(x - o.x, y - o.y);
    }

    pt operator*(ll k) const {
        return pt(k * x, k * y);
    }

    double len() const {
        return hypot((double)x, (double)y);
    }

    ll cross(pt o) const {
        return x * o.y - y * o.x;
    }

    bool operator<(pt o) const {
        return tie(x, y) < tie(o.x, o.y);
    }

    bool operator==(pt o) const {
        return tie(x, y) == tie(o.x, o.y);
    }
};

vector<pt> a;

int orientation(pt a, pt b, pt c){
    pt AB = b-a;
    pt BC = c-b;
    double v = AB.cross(BC);
    if (v < 0) return -1;
    if (v > 0) return +1;
    return 0;
}

bool cw(pt a, pt b, pt c, bool include){
    int o = orientation(a,b,c);
    return o < 0 || (include && o == 0);
}

bool ccw(pt a, pt b, pt c, bool include){
    int o = orientation(a,b,c);
    return o > 0 || (include && o == 0);
}

void convex_hull(bool include = true){
    if (a.size() == 1) return;
    sort(a.begin(), a.end());
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for (int i=1; i<a.size(); i++) {
        if (i == a.size()-1 || cw(p1, a[i], p2, include)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include)) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }

        if (i == a.size()-1 || ccw(p1, a[i], p2, include)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include)) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }

    if (include && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }

    a.clear();
    for (int i=0; i<up.size(); i++) {
        a.push_back(up[i]);
    }
    for (int i = down.size()-2; i > 0; i--) {
        a.push_back(down[i]);
    }

}

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        ll x,y;
        cin >> x >> y;
        pt pair(x,y);
        a.push_back(pair);
    }

    convex_hull();

    cout << a.size() << endl;
    for (int i=0; i<a.size(); i++) {
        cout << a[i].x << " " << a[i].y << endl;
    }
}