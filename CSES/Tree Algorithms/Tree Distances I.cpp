#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    vector<int> parent(n, -1), order = {0};
    order.reserve(n);
    for (int i = 0; i < n; ++i) {
        int& v = order[i];
        for (auto& u : graph[v]) {
            if (u == parent[v]) continue;
            parent[u] = v;
            order.emplace_back(u);
        }
    }
    
    vector<int> downMax1(n, 0), downMax2(n, 0), upMax1(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i], p = parent[v];
        if (p == -1) continue;
        int newMax = downMax1[v] + 1;
        if (newMax > downMax1[p]) {
            downMax2[p] = downMax1[p];
            downMax1[p] = newMax;
        } else if (newMax > downMax2[p]) {
            downMax2[p] = newMax;
        }
    }

    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
        int v = order[i], p = parent[v];
        if (p != -1) {
            if (downMax1[p] == downMax1[v] + 1) upMax1[v] = max(upMax1[p] + 1, downMax2[p] + 1);
            else upMax1[v] = max(upMax1[p] + 1, downMax1[p] + 1);
        }
        res[v] = max(downMax1[v], upMax1[v]);
    }
    
	for (auto& x : res) cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}