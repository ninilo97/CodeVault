#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<int> dp(m + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (auto& coin : coins) {
            if (i >= coin) dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    cout << (dp[m] == 1e9 ? -1 : dp[m]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}