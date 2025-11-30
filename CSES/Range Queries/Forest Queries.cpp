#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        int pfs = 0;
        for (int j = 1; j <= n; ++j) {
            char c; cin >> c;
            if (c == '*') pfs++;
            forest[i][j] = pfs + forest[i - 1][j];
        }
    }
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (forest[x2][y2] - forest[x2][y1 - 1] - forest[x1 - 1][y2] + forest[x1 - 1][y1 - 1]) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}