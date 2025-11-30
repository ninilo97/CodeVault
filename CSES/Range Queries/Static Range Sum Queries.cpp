#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    long long n, q; cin >> n >> q;
    vector<long long> pf(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> pf[i];
        if (i) pf[i] += pf[i - 1];
    }
    for (int i = 0; i < q; ++i) {
        long long l, r; cin >> l >> r;
        cout << pf[r - 1] - (l > 1 ? pf[l - 2] : 0) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}