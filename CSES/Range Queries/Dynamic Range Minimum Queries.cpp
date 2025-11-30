#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

class SegmentTree { // SegmentTree* st = new SegmentTree(n/maxVal + 1);
private:
    int n;
    vector<long long> t;
public:
    SegmentTree(int size) : n(size) {
        t.assign(size << 1, 0);
    }
    void init(const vector<long long>& input) {
        for (int i = 0; i < n; ++i)
            t[n + i] = input[i];
        for (int i = n - 1; i > 0; --i)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
    void modify(int p, int value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = min(t[p], t[p ^ 1]);
    }
    long long query(int l, int r) { // [l, r)
        long long res = 1e9;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};

void solve() {
    long long n, q; cin >> n >> q;
    vector<long long> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    SegmentTree* st = new SegmentTree(n);
    st -> init(vec);
    for (int i = 0; i < q; ++i) {
        long long a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            st -> modify(b - 1, c);
        } else {
            cout << (st -> query(b - 1, c)) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}