#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll dis[501][501];

void solve() {
	for (int i = 0; i < 501; ++i) {
		for (int j = 0; j < 501; ++j) {
			dis[i][j] = (i == j) ? 0 : 1e13;
		}
	}
	int n, m, q; cin >> n >> m >> q;
	for (int i = 0; i < m; ++i) {
		ll a, b, w; cin >> a >> b >> w;
		dis[a][b] = dis[b][a] = min(dis[a][b], w);
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		int a, b; cin >> a >> b;
		cout << ((dis[a][b] == 1e13) ? -1 : dis[a][b]) << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}