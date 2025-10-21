#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "01";
        return;
    }

    int m = 1 << (n - 1);
    vector<vector<int>> graph(m, vector<int>());
    for (int i = 0; i < m; ++i) {
        int son = (i << 1) % m;
        graph[i].emplace_back(son);
        graph[i].emplace_back(son | 1);
    }

    vector<int> res;
    stack<int> stk{{0}};
    while (!stk.empty()) {
        const auto& node = stk.top();
        auto& g = graph[node];
        if (g.empty()) {
            res.emplace_back(node & 1);
            stk.pop();
        } else {
            stk.push(g.back());
            g.pop_back();
        }
    }
    for (int i = 0; i < n - 2; ++i) res.emplace_back(0);
    for (auto& x : res) cout << x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}