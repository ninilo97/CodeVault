#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool vis[100001];
int cycleStartNode;
vector<int> res;

void dfs(vector<vector<int>>& adj, int v, int p = -1) {
	if (cycleStartNode >= 0) return;
	// cout << '~' << p + 1 << '\t' << v + 1 << ' ' << vis[v] << '\n';
	if (vis[v]) {
		cycleStartNode = v;
		res.emplace_back(v);
		return;
	}
	vis[v] = true;
	for (auto& neighbor : adj[v]) {
		if (neighbor == p) continue;
		dfs(adj, neighbor, v);
	}
	if (0 <= cycleStartNode and cycleStartNode < INT_MAX) {
		res.emplace_back(v);
		if (v == cycleStartNode) cycleStartNode = INT_MAX;
	}
}

void solve() {
	memset(vis, false, sizeof(vis));
	cycleStartNode = -1;

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		--a;
		--b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	for (int i = 0; i < n; ++i) {
		if (vis[i] or cycleStartNode >= 0) continue;
		dfs(adj, i);
	}
	if (res.size()) {
		reverse(res.begin(), res.end());
		cout << res.size() << '\n';
		for (auto& r : res) cout << ++r << ' ';
	} else {
		cout << "IMPOSSIBLE";
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}