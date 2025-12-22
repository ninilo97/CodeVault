#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int C = 1000, T = 3;

class DSU {
	vector<int> p, sz;
public:
	DSU(int n) : p(n), sz(n + 1, 1) {
		iota(p.begin(), p.end(), 0);
	}
	int find(int a) {
		return p[a] == a ? a : p[a] = find(p[a]);
	}
	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		p[b] = a;
		return true;
	}
	ll query() {
		vector<int> csz = sz;
		sort(sz.rbegin(), sz.rend());
		return accumulate(sz.begin(), sz.begin() + T, 1LL, multiplies<ll>());
	}
};

class Point {
	vector<ll> p;
	ll c(ll a, const ll& b) { return (a - b) * (a - b); }
public:
	Point(vector<ll>& input) : p(input) {}
	ll x() { return p[0]; }
	ll distance(const Point& other) {
		ll a = p[0] - other.p[0];
		ll b = p[1] - other.p[1];
		ll c = p[2] - other.p[2];
		return a * a + b * b + c * c;
	}
	string toString() {
		string str;
		for (auto& x : p) str += to_string(x) + ",";
		return str;
	}
};

vector<Point> processInput() {
	string input, segment;
	vector<Point> inputs;
    while (getline(cin, input)) {
		stringstream ss(input);
		vector<ll> vec;
		while (getline(ss, segment, ',')) vec.emplace_back(stoll(segment));
		inputs.emplace_back(Point(vec));
    }
	return inputs;
}

void solveTask1(vector<Point> inputs) {
	int n = inputs.size();
	vector<tuple<ll, ll, ll>> vec;
	for (ll i = 0; i < n; ++i) {
		for (ll j = i + 1; j < n; ++j) {
			vec.emplace_back(make_tuple(inputs[i].distance(inputs[j]), i, j));
		}
	}
	sort(vec.begin(), vec.end());
	DSU dsu(n);
	for (int i = 0; i < C; ++i) {
		dsu.unite(get<1>(vec[i]), get<2>(vec[i]));
	}
	cout << dsu.query() << '\n';
}

void solveTask2(vector<Point> inputs) {
	int n = inputs.size(), count = n - 1;
	vector<tuple<ll, ll, ll>> vec;
	for (ll i = 0; i < n; ++i) {
		for (ll j = i + 1; j < n; ++j) {
			vec.emplace_back(make_tuple(inputs[i].distance(inputs[j]), i, j));
		}
	}
	sort(vec.begin(), vec.end());
	DSU dsu(n);
	for (auto& [d, i, j] : vec) {
		if (dsu.unite(i, j) and --count == 0) {
			cout << inputs[i].x() * inputs[j].x() << '\n';
			return;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	// solveTask1(processInput());
	solveTask2(processInput());
	return 0;
}