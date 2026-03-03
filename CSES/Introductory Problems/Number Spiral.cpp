#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

long long solve() {
    long long x, y; cin >> x >> y;
    long long mx = max(x, y), square = mx - 1;
    return (square * square) + (
            mx & 1 ? 
            (x < y ? 2LL * mx - x : y) : 
            (y < x ? 2LL * mx - y : x)
        );
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
	return 0;
}