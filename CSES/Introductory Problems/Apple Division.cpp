#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    long long n, m, res, sum = 0; cin >> n;
    m = 1 << n;
    vector<long long> dp(m, 0);
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        sum += x;
        dp[1 << i] = x;
    }
    res = sum;
    for (int i = 1; i < m; ++i) {
        long long x = i & -i;
        dp[i] = dp[x] + dp[i ^ x];
        long long num1 = dp[i];
        long long num2 = sum - dp[i];
        res = min(res, abs(num1 - num2));
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}