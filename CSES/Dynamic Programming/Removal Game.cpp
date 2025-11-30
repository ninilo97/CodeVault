#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

long long dp[5001][5001];

long long calc(vector<long long>& vec, int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(vec[l] - calc(vec, l + 1, r), vec[r] - calc(vec, l, r - 1));
}

void solve() {
    memset(dp, -1, sizeof(dp));

    long long n, total = 0; cin >> n;
    vector<long long> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        total += vec[i];
    }
    long long diff = calc(vec, 0, n - 1);
    cout << (total + diff) / 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}