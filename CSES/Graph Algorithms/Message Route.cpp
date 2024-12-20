#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool vis[100001];
int parents[100001];

void solve() {
	memset(vis, 0, sizeof(vis));
	memset(parents, -1, sizeof(parents));

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		a--;
		b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	vis[0] = true;
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (cur == n - 1) {
			break;
		}
		for (auto& neighbor : adj[cur]) {
			if (vis[neighbor]) continue;
			vis[neighbor] = true;
			parents[neighbor] = cur;
			q.push(neighbor);
		}
	}

	// for (int i = 0; i < n; ++i) cout << i << ' ' << vis[i] << ' ' << parents[i] << '\n';

	if (vis[n - 1]) {
		vector<int> res;
		int cur = n - 1;
		while (cur) {
			res.emplace_back(cur);
			cur = parents[cur];
		}
		res.emplace_back(cur);
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