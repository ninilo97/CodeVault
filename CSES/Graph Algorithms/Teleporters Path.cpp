#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
	int n, m; cin >> n >> m;
	vector<multiset<int>> graph(n, multiset<int>());
	vector<int> inDeg(n, 0), outDeg(n, 0);
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		inDeg[--b]++;
		outDeg[--a]++;
		graph[a].insert(b);
	}

	int bad = 0, start = -1, end = -1, unique = 0;
	for (int i = 0; i < n; ++i) {
		if (outDeg[i] or inDeg[i]) unique++;
		int bal = outDeg[i] - inDeg[i];
		if (bal == 1) start = i;
		else if (bal == -1) end = i;
		else if (bal != 0) bad = 1;
	}

	if (bad or start != 0 or end != n - 1) {
		cout << "IMPOSSIBLE";
		return;
	}

	vector<int> res;
	stack<int> q{{0}};
	while (!q.empty()) {
		auto& node = q.top();
		auto& g = graph[node];
		if (g.empty()) {
			res.emplace_back(node + 1);
			q.pop();
		} else {
			q.push(*g.begin());
			g.erase(g.begin());
		}
	}
	if (set<int>(res.begin(), res.end()).size() != unique) {
		cout << "IMPOSSIBLE";
	} else {
		reverse(res.begin(), res.end());
		for (auto& x : res) cout << x << ' ';
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}