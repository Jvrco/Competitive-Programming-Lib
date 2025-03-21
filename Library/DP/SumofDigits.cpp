#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'

ll a, b;    
ll dp[10][90][2];

vector<int> getDigits(int x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

ll digitSumDP(vector<int>& digits, int pos, int sum, bool tight) {
    if (pos == digits.size()) {
        return sum; 
    }
    if (dp[pos][sum][tight] != -1) {
        return dp[pos][sum][tight];
    }

    int limit = tight ? digits[pos] : 9;
    ll result = 0;

    for (int i = 0; i <= limit; i++) {
        result += digitSumDP(digits, pos + 1, sum + i, tight && (i == limit));
    }

    dp[pos][sum][tight] = result;
    return result;
}

ll solve(int x) {
    vector<int> digits = getDigits(x);
    memset(dp, -1, sizeof(dp));
    return digitSumDP(digits, 0, 0, 1);
}

int main() {
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        ll sumB = solve(b);
        ll sumA = a == 0 ? 0 : solve(a - 1);
        cout << (sumB - sumA) << endl;
    }
    return 0;
}