#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

class SegmentTree { // SegmentTree* st = new SegmentTree(n/maxVal + 1);
private:
    vector<int> t;
    int n;
public:
    SegmentTree(int size) : n(size) {
        t.assign(size << 1, 0);
    }
    void init(vector<int>& input) {
        adjacent_difference(input.begin(), input.end(), input.begin());
        for (int i = 0; i < n; ++i)
            t[n + i] = input[i];
        for (int i = n - 1; i > 0; --i) // sum
            t[i] = t[i << 1] + t[i << 1 | 1];
    }
    void update(int l, int r, int value) {
            update(l, value);
            if (r + 1 < n) update(r + 1, -value);
    }
    void update(int p, int value) { // add
        for (t[p += n] += value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }
    int query(int p) {
        return query(0, p + 1);
    }
    int query(int l, int r) { // [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) { // sum
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
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
        long long type; cin >> type;
        if (type == 1) {
            long long a, b, u; cin >> a >> b >> u;
            st -> update(--a, --b, u);
        } else {
            long long k; cin >> k;
            cout << (st -> query(--k)) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}