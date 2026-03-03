#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, mine = 0, res = 0; cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), [&](pair<int, int>& a, pair<int, int>& b) -> bool {
        return a.second < b.second;
    });
    for (auto& [s, e] : movies) {
        if (mine <= s) {
            res++;
            mine = e;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}