#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;
vector<int> dice = {1,2,3,4,5,6};

void solve() {
    int n; cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (auto& die : dice) {
            if (i >= die) dp[i] = (dp[i] + dp[i - die]) % MOD;
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}