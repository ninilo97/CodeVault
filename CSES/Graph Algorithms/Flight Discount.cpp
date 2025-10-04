#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

long long solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<ll, ll>>> graph(n + 1, vector<pair<ll, ll>>());
	for (int i = 0; i < m; ++i) {
		ll a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
	}

	vector<vector<ll>> cost(n + 1, vector<ll>(2, LLONG_MAX));
	priority_queue<tuple<ll, ll, bool>, vector<tuple<ll, ll, bool>>, greater<>> pq;
	pq.push({0, 1, 0});
	cost[1][0] = 0;
	while(!pq.empty()) {
		auto [c, v, used] = pq.top(); pq.pop();
		if (cost[v][used] != c) continue;
		if (v == n) break;
		for (auto& [u, c] : graph[v]) {
			if (!used and cost[v][0] + (c / 2) < cost[u][1]) {
				cost[u][1] = cost[v][0] + (c / 2);
				pq.push({cost[u][1], u, 1});
			}
			if (cost[v][used] + c < cost[u][used]) {
				cost[u][used] = cost[v][used] + c;
				pq.push({cost[u][used], u, used});
			}
		}
	}
	return cost[n][1];
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << solve() << '\n';
	return 0;
}