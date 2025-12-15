#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    for (int i = 0; i < n; ++i) cin >> pages[i];

    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= prices[i]; --j) {
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }
    cout << dp[m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}