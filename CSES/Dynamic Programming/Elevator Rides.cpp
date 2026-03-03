#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m, limit; cin >> n >> limit;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    m = 1 << n;
    vector<pair<int, int>> dp(m, {2e9, 2e9});
    dp[0] = {1, 0};
    for (int mask = 1; mask < m; ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) continue;
            auto& [count, weight] = dp[mask ^ (1 << i)];
            bool overLimit = weight + weights[i] > limit;
            dp[mask] = min(dp[mask], {count + overLimit, weights[i] + (overLimit ? 0 : weight)});
        }
    }
    cout << dp[m - 1].first << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}