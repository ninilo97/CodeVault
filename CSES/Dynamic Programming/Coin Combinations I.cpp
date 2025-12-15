#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        for (auto& coin : coins) {
            if (i >= coin) dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
    cout << dp[m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}