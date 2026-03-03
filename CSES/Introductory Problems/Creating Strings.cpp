#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void generate(map<char, int>& map, string& temp, vector<string>& res, int& size) {
    if (temp.size() == size) {
        res.emplace_back(temp);
        return;
    }
    for (auto [k, v] : map) {
        if (!v) continue;
        map[k]--;
        temp.append(1, k);
        generate(map, temp, res, size);
        map[k]++;
        temp.pop_back();
    }
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    map<char, int> map;
    for (auto& c : s) map[c]++;
    vector<string> res;
    string temp;
    generate(map, temp, res, n);
    cout << res.size() << '\n';
    for (auto& x : res) cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}