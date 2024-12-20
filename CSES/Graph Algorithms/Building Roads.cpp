#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int ranks[100001];
int parents[100001];

void make_set(int v) {
	ranks[v] = 0;
	parents[v] = v;
}

int find_set(int v) {
	if (v == parents[v]) return v;
	return parents[v] = find_set(parents[v]);
}

bool union_sets(int v1, int v2) {
	int p1 = find_set(v1);
	int p2 = find_set(v2);
	if (p1 != p2) {
		if (ranks[p2] < ranks[p1]) swap(p1, p2);
		parents[p1] = p2;
        ranks[p2] += ranks[p1];
	}
	return p1 != p2;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		make_set(i);
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		union_sets(a, b);
	}
	vector<pair<int, int>> res;
	for (int i = 2; i <= n; ++i) {
		if (union_sets(1, i)) res.emplace_back(1, i);
	}
	cout << res.size() << '\n';
	for (auto r : res) cout << r.first << ' ' << r.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}
