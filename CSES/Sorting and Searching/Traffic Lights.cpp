#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n, m; cin >> n >> m;
    unordered_map<int, int> map{{n,1}};
    set<int> largest{{n}};
    set<int> left{{-n, 0}};
    set<int> right{{0, n}};

    auto remove = [&](int x) -> void {
        if (--map[x] == 0) largest.erase(x);
    };

    auto add = [&](int x) -> void {
        largest.insert(x);
        map[x]++;
    };

    for (int i = 0; i < m; ++i) {
        int a; cin >> a;
        auto down = -(*left.upper_bound(-a));
        auto up = (*right.upper_bound(a));

        left.insert(-a);
        right.insert(a);

        remove(up - down);
        add(up - a);
        add(a - down);

        cout << *largest.rbegin() << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}