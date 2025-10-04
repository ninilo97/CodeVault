#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;

vector<vector<long long>> mmul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
	vector<vector<long long>> res{{0, 0}, {0, 0}};
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
	return res;
}

vector<vector<long long>> mpow(vector<vector<long long>>& b, long long e) {
	vector<vector<long long>> res{{0, 1}, {1, 1}};
    for (; e; e >>= 1, b = mmul(b, b))
        if (e & 1) res = mmul(res, b);
    return res;
}

long long solve() {
	long long n; cin >> n;
	if (n < 2) return n;
	vector<vector<long long>> res{{0, 1}, {1, 1}};
	return mpow(res, n)[0][0];
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << solve();
	return 0;
}
