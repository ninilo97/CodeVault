#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
 
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pair<ll, ll>>> adj(n + 1, vector<pair<ll, ll>>());
	for (int i = 0; i < m; ++i) {
		ll a, b, w; cin >> a >> b >> w;
		adj[a].emplace_back(b, w);
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 1});
	vector<ll> dis(n + 1, LLONG_MAX);
	vector<bool> vis(n + 1, false);
	dis[1] = 0;
	while (pq.size()) {
		auto [_, v] = pq.top(); pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (auto& [u, w] : adj[v]) {
			if (dis[v] + w < dis[u]) {
				dis[u] = dis[v] + w;
				pq.push({dis[u], u});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << dis[i] << ' ';
	}
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
