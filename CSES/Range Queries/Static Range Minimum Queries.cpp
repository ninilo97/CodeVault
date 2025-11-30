#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

class SparseTable { // SparseTable* st = new SparseTable(n);
private:
    int n, k;
    vector<vector<int>> t;
public:
    SparseTable(int size) : n(size) {
        k = log2(n);
        t.assign(k + 1, vector<int>(n, 0));
    }
    void init(vector<int> vec) {
        copy(vec.begin(), vec.end(), t[0].begin());
        for (int i = 1; i <= k; ++i) {
            int m = 1 << i, p = 1 << (i - 1);
            for (int j = 0; j + m <= n; ++j) {
                t[i][j] = min(t[i - 1][j], t[i - 1][j + p]);
            }
        }
    }
    int query(int l, int r) {
        int len = log2(r - l + 1);
        return min(t[len][l], t[len][r - (1 << len) + 1]);
    }
};

void solve() {
    long long n, q; cin >> n >> q;
    vector<long long> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    SparseTable* st = new SparseTable(n);
    st -> init(vec);
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        cout << (st -> query(--l, --r)) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}