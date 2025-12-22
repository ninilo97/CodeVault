#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


vector<string> processInput() {
	string input;
	vector<string> inputs;
    while (getline(cin, input)) {
		inputs.emplace_back(input);
    }
	return inputs;
}

void solveTask1(vector<string> inputs) {
	long long n = inputs.size(), m = inputs[0].size(), res = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (inputs[i - 1][j] == 'S') {
				if (inputs[i][j] == '^') {
					if (j > 0) inputs[i][j - 1] = 'S';
					if (j < m - 1) inputs[i][j + 1] = 'S';
					res++;
				} else {
					inputs[i][j] = 'S';
				}
			}
		}
	}
	cout << res << '\n';
}

void solveTask2(vector<string> inputs) {
	long long n = inputs.size(), m = inputs[0].size();
	vector<vector<long long>> count(n, vector<long long>(m, 0));
	for (int i = 0; i < m; ++i) {
		if (inputs[0][i] == 'S') count[0][i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (inputs[i - 1][j] == 'S') {
				if (inputs[i][j] == '^') {
					if (j > 0) {
						inputs[i][j - 1] = 'S';
						count[i][j - 1] += count[i - 1][j];
					}
					if (j < m - 1) {
						inputs[i][j + 1] = 'S';
						count[i][j + 1] += count[i - 1][j];
					}
				} else {
					inputs[i][j] = 'S';
					count[i][j] += count[i - 1][j];
				}
			}
		}
	}
	cout << accumulate(count[n - 1].begin(), count[n - 1].end(), 0LL) << '\n';
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