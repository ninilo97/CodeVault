#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    long long n; cin >> n;
    vector<long long> vec(n), pf(n, 0);
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        dp[i][i] = vec[i];
        pf[i] += vec[i];
        if (i) pf[i] += pf[i - 1];
    }
    auto sum = [&](int l, int r) -> long long {
        return pf[r] - (l ? pf[l - 1] : 0);
    };
    for (int len = 1; len < n; ++len) {
        for (int l = 0, r = l + len; r < n; ++l, ++r) {
            dp[l][r] = max(vec[l] + (sum(l + 1, r) - dp[l + 1][r]), vec[r] + (sum(l, r - 1) - dp[l][r - 1]));
        }
    }
    cout << dp[0][n - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}