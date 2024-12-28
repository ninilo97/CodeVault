#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

class Edge {
public:
	int a;
	int b;
	int w;
	Edge(int a, int b, int w): a(a), b(b), w(w) {}
};

void solve() {
	int n, m; cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; ++i) {
		int a, b, w; cin >> a >> b >> w;
		edges.emplace_back(a, b, w);
	}
	vector<ll> dis(n + 1, -1e13), onRoute(n + 1, 0);
	dis[1] = 0;
	onRoute[1] |= 1;
	onRoute[n] |= 2;
	for (int i = 0; i < n; ++i) {
		for (auto& edge : edges) {
			dis[edge.b] = max(dis[edge.b], dis[edge.a] + edge.w);
			if (onRoute[edge.b] & 2) onRoute[edge.a] |= 2;
			if (onRoute[edge.a] & 1) onRoute[edge.b] |= 1;
		}
	}
	ll res = dis[n];
	for (auto& edge : edges) {
		if (onRoute[edge.b] == 3 and dis[edge.b] < dis[edge.a] + edge.w) {
			res = -1;
			break;
		}
	}
	cout << res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}