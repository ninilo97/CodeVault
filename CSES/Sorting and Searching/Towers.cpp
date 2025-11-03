#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        auto x = s.lower_bound(a + 1);
        if (x != s.end()) s.erase(x);
        s.insert(a);
    }
    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}