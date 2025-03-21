#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<ll,ll,ll>
#define quad tuple<ll,ll,ll,ll>
const int dx[] = {1,0,0,-1};
const int dy[] = {0,1,-1,0};
ll INF = 1e18;

double newLogK(ll n,ll k) { //turn number n from log(10) to log(k)
    return log(n) / log(k);
}

bool bigger(string& a, string& b){ //biggerb binary number with the same number of bits
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '1' && b[i] == '0') return true;
        if (a[i] == '0' && b[i] == '1') return false;
    }
    return false;
};

string xorCalc(string& a, string& b){ //calculates xor between two bit strings.
    string res = "";
    for (int i=0; i<a.size(); i++) {
        if (a[i] == b[i]) res += '0';
       else res += '1';
    }
    return res;
}

void solve() {
    int n;
    ll a[n];
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;
    sort(a,a+n,greater<ll>()); //sort reversed

    cin >> n;
    char c;
    cin >> c;
    int valMin = c - 'a'; //char(minusculo) to int(0-based)
    int valMax = c - 'A'; //char(maiúsculo) to int(0-based)
    char cMin = valMin + 'a'; //int(0-based) to char
    char cMax = valMax + 'a'; //int(-23based) to char
    char cNum = n + '0'; //int to char numeric
    int num = cNum - '0'; //char numeric to int

    cout << valMin << endl;
    cout << cMin << endl;
    cout << valMax << endl;
    cout << cMax << endl;
    cout << cNum << endl;
    cout << num << endl;

    double db = 9.387218749214;
    cout << fixed << setprecision(6)<< endl; //fix the ouput to print 6 decimal cases;
}

int main(){
    fIo;
    const int M = 0;
    int t = 1;
    if(M) cin>>t;
    while(t--){
        solve();
    }
} 