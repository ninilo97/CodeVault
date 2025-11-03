#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        s.insert(-a);
    }
    for (int i = 0; i < m; ++i) {
        int a; cin >> a;
        auto x = s.lower_bound(-a);
        if (x != s.end()) {
            cout << -(*x) << '\n';
            s.erase(x);
        } else {
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}