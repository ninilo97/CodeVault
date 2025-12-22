#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<ll,ll>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<ll, ll>> processInput() {
	string input;
	vector<pair<ll, ll>> inputs;
    while (getline(cin, input)) {
		auto x = input.find(',');
		inputs.emplace_back(stoll(input.substr(0, x)), stoll(input.substr(x + 1)));
    }
	return inputs;
}


void solveTask1(vector<pair<ll, ll>> inputs) {
	unordered_map<ll, vector<int>> m1, m2;
	ll n = inputs.size(), mn1 = 1e9, mn2 = 1e9, mx1 = -1e9, mx2 = -1e9;
	for (int i = 0; i < n; ++i) {
		auto& [x, y] = inputs[i];
		m1[x + y].emplace_back(i);
		m2[x - y].emplace_back(i);
		mn1 = min(mn1, x + y);
		mn2 = min(mn2, x - y);
		mx1 = max(mx1, x + y);
		mx2 = max(mx2, x - y);
	}

	auto area = [&](int& i, int& j) -> ll {
		return (labs(inputs[i].first - inputs[j].first) + 1) * (labs(inputs[i].second - inputs[j].second) + 1);
	};

	ll res = 0;
	for (auto& i : m1[mn1]) for (auto& j : m1[mx1]) res = max(res, area(i, j));
	for (auto& i : m2[mn2]) for (auto& j : m2[mx2]) res = max(res, area(i, j));
	cout << res << '\n';
}

void print(vector<vector<ll>>& m) {
	for (auto& x : m) {
		for (auto& y : x) cout << y << ' '; cout << '\n';
	}
	cout << '\n';
}

void solveTask2(vector<pair<ll, ll>> inputs) {
	vector<int> pointsX({-1}), pointsY({-1});
	for (auto& [x, y] : inputs) swap(x, y);
	for (auto& [x, y] : inputs) {
		pointsX.emplace_back(x);
		pointsX.emplace_back(x + 1);
		pointsX.emplace_back(x - 1);
		pointsY.emplace_back(y);
		pointsY.emplace_back(y + 1);
		pointsY.emplace_back(y - 1);
	}
	sort(pointsX.begin(), pointsX.end());
	pointsX.erase(unique(pointsX.begin(), pointsX.end()), pointsX.end());
	sort(pointsY.begin(), pointsY.end());
	pointsY.erase(unique(pointsY.begin(), pointsY.end()), pointsY.end());
	
	unordered_map<ll, ll> pointXIndex, pointYIndex;
	int n = pointsX.size(), m = pointsY.size(), k = inputs.size();
	for (int i = 1; i < n; ++i) pointXIndex[pointsX[i]] = i;
	for (int i = 1; i < m; ++i) pointYIndex[pointsY[i]] = i;

	vector<vector<ll>> map(n, vector<ll>(m, 0));
	for (auto& [x, y] : inputs) {
		map[pointXIndex[x]][pointYIndex[y]]++;
	}

	for (int i = 1; i < n; ++i) {
		int first = -1, last = -1;
		for (int j = 1; j < m; ++j) {
			if (map[i][j] != 1) continue;
			if (first == -1) first = j;
			last = j;
		}
		if (first != -1)
			for (int j = first; j <= last; ++j) if (!map[i][j]) map[i][j] = 2;
	}

	// print(map);
	for (int j = 1; j < m; ++j) {
		int first = -1, last = -1;
		for (int i = 1; i < n; ++i) {
			if (map[i][j] != 1) continue;
			if (first == -1) first = i;
			last = i;
		}
		if (first != -1)
			for (int i = first; i <= last; ++i) if (!map[i][j]) map[i][j] = 2;
	}

	queue<pair<ll, ll>> que;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((i == 0 or i == n - 1) and (j == 0 or j == m - 1) and map[i][j] == 0) {
				que.push({i, j});
				map[i][j] = 2;
			}
			if (!map[i][j]) continue;
			map[i][j] = 1;
		}
	}

	// print(map);

	while (!que.empty()) {
		auto [x, y] = que.front(); que.pop();
		for (auto& [dx, dy] : dirs) {
			ll nx = x + dx, ny = y + dy;
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or map[nx][ny]) continue;
			que.push({nx, ny});
			map[nx][ny] = 2;
		}
	}

	// print(map);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 2) map[i][j] = 0;
			else if (map[i][j] == 0) map[i][j] = 1;
		}
	}	
	// print(map);

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) map[i][j] += map[i][j - 1];
		for (int j = 1; j < m; ++j) map[i][j] += map[i - 1][j];
	}

	auto diff = [&](ll& a, ll& b) -> ll {
		return labs(a - b) + 1;
	};

	auto area = [&](ll& x1, ll& y1, ll& x2, ll& y2) -> ll {
		return diff(x1, x2) * diff(y1, y2);
	};

	auto diffPF = [&](ll x, ll y) -> ll {
		return map[x][y];
	};

	auto areaPF = [&](ll& x1, ll& y1, ll& x2, ll& y2) -> ll {
		return diffPF(x2, y2) - diffPF(x1 - 1, y2) - diffPF(x2, y1 - 1) + diffPF(x1 - 1, y1 - 1);
	};

	ll res = 0;
	for (int i = 0; i < k; ++i) {
		ll& x1 = inputs[i].first, y1 = inputs[i].second;
		for (int j = i + 1; j < k; ++j) {
			ll& x2 = inputs[j].first, y2 = inputs[j].second;
			ll xMin = min(x1, x2), xMax = max(x1, x2), yMin = min(y1, y2), yMax = max(y1, y2);
			ll a1 = pointXIndex[xMin], b1 = pointYIndex[yMin], a2 = pointXIndex[xMax], b2 = pointYIndex[yMax];
			ll aa = area(a1, b1, a2, b2);
			ll bb = areaPF(a1, b1, a2, b2);
			if (aa == bb) { res = max(res, area(xMin, yMin, xMax, yMax)); }
		}
	}
	cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	// solveTask1(processInput());
	solveTask2(processInput());
	return 0;
}