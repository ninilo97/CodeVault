#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    vector<set<int>> graph(n, set<int>());
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (const auto& x : graph) {
        if (x.size() & 1) {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    vector<int> res;
    stack<int> s{{0}};
    while (!s.empty()) {
        auto& node = s.top();
        auto& g = graph[node];
        if (g.empty()) {
            res.emplace_back(node + 1);
            s.pop();
        } else {
            s.push(*g.begin());
            graph[*g.begin()].erase(node);
            g.erase(g.begin());
        }
    }
    if (res.size() == m + 1) {
        reverse(res.begin(), res.end());
        for (auto& x : res) {
            cout << x << ' ';
        }
    } else {
        cout << "IMPOSSIBLE";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}