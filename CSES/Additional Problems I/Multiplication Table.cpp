#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    long long n; cin >> n;
    long long k = n * n / 2 + 1;
    
    auto check = [&](long long m) -> bool {
        long long res = 0;
        for (long long i = 1; i <= n; ++i) {
            res += min(n, m / i);
        }
        return res >= k;
    };

    long long l = 1, r = n * n, res = 1;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (check(m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}