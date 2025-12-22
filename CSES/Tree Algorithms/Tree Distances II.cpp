#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
	int n; cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 1; i < n; ++i) {
		int x, y; cin >> x >> y;
		--x; --y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}

	vector<int> parent(n, -1), order = {0};
	order.reserve(n);
	for (int i = 0; i < n; ++i) {
		int& v = order[i];
		for (auto& u : graph[v]) {
			if (u == parent[v]) continue;
			parent[u] = v;
			order.emplace_back(u);
		}
	}

	vector<ll> upCost(n, 0), downCost(n, 0), downCount(n, 1);
	for (int i = n - 1; i >= 0; --i) {
		int v = order[i], p = parent[v];
		if (p == -1) continue;
		downCost[p] += downCost[v] + downCount[v];
		downCount[p] += downCount[v];
	}

	vector<ll> res(n, 0);
	for (int i = 0; i < n; ++i) {
		int v = order[i], p = parent[v];
		if (p != -1) {
			ll parenUpCost = upCost[p] + (downCost[p] - downCost[v] - downCount[v]);
			ll parenUpCount = n - downCount[v];
			upCost[v] = parenUpCost + parenUpCount;
		}
		res[v] = upCost[v] + downCost[v];
	}

	for (auto& x : res) cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}