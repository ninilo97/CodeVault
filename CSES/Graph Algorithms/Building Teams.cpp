#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool vis[100001];
int team[100001];

void solve() {
	memset(vis, 0, sizeof(vis));
	memset(team, -1, sizeof(team));

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		--a;
		--b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		q.push(i);
		team[i] = vis[i] = 1;
		while (q.size()) {
			int v = q.front(); q.pop();
			for (auto& neighbor : adj[v]) {
				if (vis[neighbor]) {
					if (team[v] != team[neighbor]) continue;
					else { cout << "IMPOSSIBLE"; return; }
				}
				vis[neighbor] = true;
				team[neighbor] = !team[v];
				q.push(neighbor);
			}
		}
		// for (int i = 0; i < n; ++i) {
		// 	cout << team[i] + 1 << ' ';
		// }
		// cout << '\n';
	}
	for (int i = 0; i < n; ++i) {
		cout << ++team[i] << ' ';
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}