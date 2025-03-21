#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Node {
    map<int, int> next;
    int sub_cnt = 0;
};

struct Trie {
    vector<Node> tr;

    Trie() : tr(1) {}

    void add(int x){
        int cur = 0;
        
        for (int b=29; b>=0; b--) {
            int id = (x>>b) & 1;

            if (tr[cur].next[id] == 0) {
                int sz = tr.size();
                tr[cur].next[id] = sz;
                tr.emplace_back();
            }
    
            tr[cur].sub_cnt += 1;
            cur = tr[cur].next[id];
        }
        tr[cur].sub_cnt += 1;
    }

    void remove(int x){
        int cur = 0;
        vector<pii> path;
        
        for (int b=29; b>=0; b--) {
            int id = (x >> b) & 1;
            if (tr[cur].next.find(id) == tr[cur].next.end()) return;

            path.push_back({cur, id});
            cur = tr[cur].next[id];
        }
        tr[cur].sub_cnt--;
        
        for (auto &p : path) {
            tr[p.first].sub_cnt--;
        }
        
        for (int i=path.size()-1; i>=0; i--) {
            int par = path[i].first;
            int id = path[i].second;
            int child = tr[par].next[id];
            if (tr[child].sub_cnt == 0) {
                tr[par].next.erase(id);
            }
        }
    }

    int query(int x){ //find min xor possible between x and a node in the tree
        int cur = 0;
        int ans = 0;
        
        for (int b = 29; b >= 0; b--) {
            int id = (x >> b) & 1;

            if (tr[cur].next.find(id) == tr[cur].next.end() || tr[tr[cur].next[id]].sub_cnt <= 0) {
                ans += (1 << b);
                id ^= 1;
            }
            assert(tr[cur].next.find(id) != tr[cur].next.end() && tr[tr[cur].next[id]].sub_cnt > 0);
            cur = tr[cur].next[id];
        }
        return ans;
    }
    
};  

void solve(){
    Trie trie;
    set<int> s;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int op,x;
        cin >> op >> x;
        if (op == 0) {
            if (s.find(x) == s.end()) {
                trie.add(x);
                s.insert(x);
            }
        }
        else if (op == 2) cout << trie.query(x) << endl;
        else {
            if (s.find(x) != s.end()) {
                trie.remove(x);
                s.erase(x);
            }
        }
    }
}