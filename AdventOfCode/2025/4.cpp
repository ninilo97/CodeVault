#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

vector<string> processInput() {
	string input;
	vector<string> inputs;
    while (getline(cin, input)) {
		inputs.emplace_back(input);
    }
	return inputs;
}

void solveTask1(vector<string> inputs) {
	int n = inputs.size(), m = inputs[0].size(), res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (inputs[i][j] != '@') continue;
			
			int count = 0;
			for (int d = 0; d < 8; ++d) {
				int ii = i + dx[d], jj = j + dy[d];
				if (ii < 0 or ii >= n or jj < 0 or jj >= m) continue;
				if (inputs[ii][jj] == '@') count++;
			}
			if (count < 4) res++;
		}
	}
	cout << res << '\n';
}

void solveTask2(vector<string> inputs) {
	int n = inputs.size(), m = inputs[0].size();
	vector<vector<long long>> neighbors(n, vector<long long>(m, 0));
	queue<pair<int, int>> que;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int count = 0;
			for (int d = 0; d < 8; ++d) {
				int ii = i + dx[d];
				int jj = j + dy[d];
				if (ii < 0 or ii >= n or jj < 0 or jj >= m) continue;
				if (inputs[ii][jj] == '@') count++;
			}
			neighbors[i][j] = count;
			if (inputs[i][j] == '@' and count < 4) que.push({i, j});
		}
	}

	long long res = 0;
	while (!que.empty()) {
		auto [x, y] = que.front(); que.pop();
		if (inputs[x][y] != '@') continue;
		inputs[x][y] = '.';
		res++;
		for (int d = 0; d < 8; ++d) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if (--neighbors[nx][ny] < 4 and inputs[nx][ny] == '@') {
				que.push({nx, ny});
			}
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