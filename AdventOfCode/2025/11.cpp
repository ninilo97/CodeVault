#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<string, string>> edges;

void processInput() {
	string input, part;
    while (getline(cin, input)) {
		auto x = input.find(':');
		string p = input.substr(0, x);
		string c = input.substr(x + 2);
		istringstream ss(c);
		while (getline(ss, part, ' ')) {
			edges.emplace_back(p, part);
		}
    }
}

int count(unordered_map<string, vector<string>>& graph, string& c, string& e) {
	if (c == e) return 1;
	int res = 0;
	for (auto& neighbor : graph[c]) res += count(graph, neighbor, e);
	return res;
}

string you = "you", out = "out", svr = "svr", fft = "fft", dac = "dac";

void solveTask1() {
	unordered_map<string, vector<string>> graph;
	for (auto& [p, c] : edges) {
		graph[p].emplace_back(c);
	}
	cout << count(graph, you, out) << '\n';
}

void dfs(vector<vector<int>>& graph, vector<int>& topoIndex, vector<int>& visited, int node) {
	visited[node] = 1;
	for (auto& neighbor : graph[node]) {
		if (visited[neighbor]) continue;
		dfs(graph, topoIndex, visited, neighbor);
	}
	topoIndex.emplace_back(node);
}

ll numberOfPaths(int& n, vector<vector<int>>& graph2, vector<int>& topoIndex, int start, int end) {
	vector<ll> dp(n, 0);
	dp[start] = 1;
	for (auto& node : topoIndex) {
		for (auto& neighbor : graph2[node]) {
			dp[node] += dp[neighbor];
		}
	}
	return dp[end];
}

void solveTask2() {
	int n = 0;
	set<string> s;
	for (auto& [p, c] : edges) {
		s.insert(p);
		s.insert(c);
	}
	unordered_map<string, int> index;
	unordered_map<int, string> rindex;
	for (auto& x : s) {
		index[x] = n;
		rindex[n++] = x;
	}

	vector<vector<int>> graph1(n, vector<int>()), graph2(n, vector<int>());
	for (auto& [p, c] : edges) {
		graph1[index[p]].emplace_back(index[c]);
		graph2[index[c]].emplace_back(index[p]);
	}
	vector<int> topoIndex, visited(n, 0);
	dfs(graph1, topoIndex, visited, index[svr]);
	reverse(topoIndex.begin(), topoIndex.end());

	vector<pair<string, string>> order ={{fft, dac}, {dac, fft}};
	ll res = 0;
	for (auto& [f, s] : order) {
		ll a = numberOfPaths(n, graph2, topoIndex, index[svr], index[f]);
		ll b = numberOfPaths(n, graph2, topoIndex, index[f], index[s]);
		ll c = numberOfPaths(n, graph2, topoIndex, index[s], index[out]);
		res += a * b * c;
	}
	cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	processInput();
	// solveTask1();
	solveTask2();
	return 0;
}