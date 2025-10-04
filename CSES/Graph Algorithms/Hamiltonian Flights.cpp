#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

int n, m, k;

long long countWaysDP(vector<vector<int>>& graph, vector<vector<long long>>& dp, int v = 0, int mask = 1) {
	if (mask & (1 << (n - 1)) and mask != k) return 0;
	if (dp[v][mask] != -1) return dp[v][mask];
	dp[v][mask] = 0;
	for (auto& u : graph[v]) {
		if (mask & (1 << u)) continue;
		dp[v][mask] = (dp[v][mask] + countWaysDP(graph, dp, u, mask | (1 << u))) % MOD;
	}
	return dp[v][mask];
}

long long solveTopDown() {
	cin >> n >> m;
	k = (1 << n) - 1;
	vector<vector<int>> graph(n, vector<int>());
	vector<vector<long long>> dp(n, vector<long long>(1 << n, -1));
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		graph[--x].emplace_back(--y);
	}
	dp[n - 1][k] = 1;
	return countWaysDP(graph, dp);
}

long long solveBottomUp() {
	cin >> n >> m;
	k = (1 << n) - 1;
	vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
	vector<vector<int>> flightsTo(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int start, end; cin >> start >> end;
		flightsTo[--end].emplace_back(--start);
	}
	dp[1][0] = 1;
	for (int mask = 2; mask < (1 << n); ++mask) {
		if (!(mask & 1)) continue;
		if (mask & (1 << (n - 1)) and mask != k) continue;
		for (int end = 0; end < n; ++end) {
			if (!(mask & (1 << end))) continue;
			
			int prev = mask ^ (1 << end);
			for (auto& start : flightsTo[end]) {
				if (!(mask & (1 << start))) continue;
				dp[mask][end] = (dp[mask][end] + dp[prev][start]) % MOD;
			}
		}
	}
	return dp[k][n - 1];
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	// cout << solveTopUp() << '\n';
	cout << solveBottomUp() << '\n';
	return 0;
}