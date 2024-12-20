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
	return l <= m and m <= r;
}

void solve() {
	memset(vis, false, sizeof(vis));
	memset(path, -1, sizeof(path));

	int n, m; cin >> n >> m;

	vector<string> grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}

	pair<int, int> start = {-1, -1}, stop = {-1, -1};
	queue<pair<int, int>> q, monsterQ;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 'A') {
				q.push({i, j});
				start = {i, j};
				vis[i][j] = true;
			} else if (grid[i][j] == 'M') {
				monsterQ.push({i, j});
				vis[i][j] = true;
			}
		}
	}

	bool found = false;
	while (q.size() and !found) {
		int numberOfMonsterMoves = monsterQ.size();
		for (int i = 0; i < numberOfMonsterMoves; ++i) {
			auto [mx, my] = monsterQ.front(); monsterQ.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = mx + dx[i], ny = my + dy[i];
				if (inRange(0, nx, n - 1) and
					inRange(0, ny, m - 1) and
					grid[nx][ny] != '#' and
					!vis[nx][ny]) {
						vis[nx][ny] = true;
						monsterQ.push({nx, ny});
				}
			}
		}

		int numberOfMoves = q.size();
		for (int i = 0; i < numberOfMoves; ++i) {
			auto [x, y] = q.front(); q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!inRange(0, nx, n - 1) or !inRange(0, ny, m - 1)) {
					found = true;
					stop = {x, y};
					break;
				}
				if (grid[nx][ny] != '#' and !vis[nx][ny]) {
						vis[nx][ny] = true;
						q.push({nx, ny});
						path[nx][ny] = i;
				}
			}
		}
	}

	if (found) {
		cout << "YES\n";
		string res = "";
		while (stop != start) {
			int idx = path[stop.first][stop.second];
			res += dir[idx];
			stop = {stop.first - dx[idx], stop.second - dy[idx]};
		}
		reverse(res.begin(), res.end());
		cout << res.size() << '\n' << res;
	} else {
		cout << "NO";
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}