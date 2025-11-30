#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    long long n, x; cin >> n >> x;
    vector<long long> vec(n), fset, bset;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    
    auto process = [&](vector<long long>& s, int l, int r) -> void {
        int len = r - l + 1;
        for (int i = 0; i < (1 << len); ++i) {
            long long sum = 0;
            for (int j = 0; j < len; ++j) if (i & (1 << j)) sum += vec[l + j];
            s.emplace_back(sum);
        }
        sort(s.begin(), s.end());
    };

    process(fset, 0, n / 2 - 1);
    process(bset, n / 2, n - 1);

    long long res = 0;
    for (long long num : fset) {
        auto left = lower_bound(bset.begin(), bset.end(), x - num);
        auto right = upper_bound(bset.begin(), bset.end(), x - num);
        res += right - left;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}