#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool vis[1000][1000];
int path[1000][1000];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dir[4] = {'R', 'D', 'L', 'U'};

bool inRange(int l, int m, int r) {
	return l <= m and m < r;
}

void solve() {
	memset(vis, false, sizeof(vis));
	memset(path, -1, sizeof(path));

	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}

	int sx = -1, sy = -1, ex = -1, ey = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 'A') {
				sx = i;
				sy = j;
			} else if (grid[i][j] == 'B') {
				ex = i;
				ey = j;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		if (x == ex and y == ey) break;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!inRange(0, nx, n)) continue;
			if (!inRange(0, ny, m)) continue;
			if (vis[nx][ny]) continue;
			if (grid[nx][ny] == '#') continue;
			vis[nx][ny] = true;
			path[nx][ny] = i;
			q.push({nx, ny});
		}
	}

	if (vis[ex][ey]) {
		cout << "YES\n";
		string res = "";
		while (!(ex == sx and ey == sy)) {
			int idx = path[ex][ey];
			res += dir[idx];
			ex -= dx[idx];
			ey -= dy[idx];
		}
		reverse(res.begin(), res.end());
		cout << res.size() << '\n';
		cout << res;
	} else {
		cout << "NO";
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}