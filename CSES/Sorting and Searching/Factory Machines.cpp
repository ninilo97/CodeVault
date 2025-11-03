#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    long long n, t; cin >> n >> t;
    vector<long long> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }

    auto check = [&](long long totalTime) -> bool {
        long long productCount = 0LL;
        for (long long time : times) {
            productCount += totalTime / time;
            if (productCount >= t) return true;
        }
        return false;
    };

    long long l = 1, r = 1000000000000000000LL;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}