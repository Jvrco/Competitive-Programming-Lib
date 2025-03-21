#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define pii pair<int, int>
#define pll pair<ll, ll>

struct Node {
    map<int, int> next;
    int str;
};

struct Trie {
    vector<Node> tr;

    Trie() : tr(1) {}

    void add(string s,int i){
        int cur = 0;
    
        for (char c: s) {
            if (tr[cur].next[c-'a'] == 0) {
                int sz = tr.size();
                tr[cur].next[c-'a'] = sz;
                tr.emplace_back();
            }
    
            tr[cur].str = i;
            cur = tr[cur].next[c-'a'];
        }
        tr[cur].str = i;
    }

    int query(string s){
        int cur = 0;
        for (char c: s) {
            if (tr[cur].next[c-'a'] == 0) return 0;
            cur = tr[cur].next[c-'a'];
        }
        return tr[cur].str;
    }
};

void solve(){
    Trie trie;
    int n,q;
    cin >> n;
    map<int,string> code;
    map<string,int> m;
    int cnt = 0; 
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        m[s]++;
    }

    vector<pair<int,string>> aux;
    pair<int, string> p;
    for (auto &pair: m) {
        p = {pair.second, pair.first};
        p.first -= 2 * p.first;
        aux.push_back(p);
    }

    sort(aux.begin(), aux.end());

    for (int i=aux.size()-1; i>=0; i--) {
        auto[num, s] = aux[i];
        trie.add(s,i+1);
        code[i+1] = s;
    }

    cin >> q;
    for (int i=0; i<q; i++) {
        string s;
        cin >> s;
        int coded = trie.query(s);
        if (coded == 0) cout << -1 << endl;

        else {
            string ans = code[coded];
            int max = m[ans]; 
            cout << ans << " " << max << endl;
        }
    }
}