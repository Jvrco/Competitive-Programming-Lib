#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXV = 200000;
const ll INF = LLONG_MAX;
bool visited[MAXV];
vector<pair<int, ll>> adj[MAXV];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> v = a;
    sort(v.begin(), v.end());

    vector<ll> prefix(n + 1, 0);
    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + v[i];
    }
    ll total = prefix[n];  

    vector<ll> w;          
    vector<ll> freq;
    w.push_back(v[0]);
    freq.push_back(1);
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1]) {
            freq.back()++;
        } else {
            w.push_back(v[i]);
            freq.push_back(1);
        }
    }
    int k = w.size();

    vector<ll> sl(k, 0);
    
    int idx = 0;
    for(int i = 0; i < k; i++){
        while(v[idx] < w[i]) {
            idx++;
        }
        sl[i] = prefix[idx];
        idx += freq[i];
    }
    

    vector<ll> pw(k+1, 0);
    for(int i = 0; i < k; i++){
        pw[i+1] = pw[i] + freq[i]*w[i];
    }

    map<ll, bool> ans;

    for(int i = 0; i < k; i++){
        ll cur = w[i] + sl[i];
        if(cur <= w[i]) {
            ans[w[i]] = false;
            continue;
        }

        ll eaten = sl[i];
        ll same = freq[i] - 1;
        cur   += same * w[i];
        eaten += same * w[i];

        bool ok = true;
        int p = i + 1;
        while(p < k){
            if(cur <= w[p]){
                ok = false;
                break;
            }
            int pprime = (upper_bound(w.begin() + p, w.end(), cur - 1) - w.begin()) - 1;
            if(pprime < p){
                ok = false;
                break;
            }
            ll bs = pw[pprime + 1] - pw[p];
            cur   += bs;
            eaten += bs;
            p = pprime + 1;
        }

        ans[w[i]] = (ok && (eaten == total - w[i]));
    }

    for(int i = 0; i < n; i++){
        cout << (ans[a[i]] ? 'T' : 'N');
    }
    cout << endl;

    return 0;
}
