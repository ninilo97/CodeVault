#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    string s; cin >> s;
    int n = s.size(), map[26] = {0}, minChar = 0;
    for (auto& c : s) {
        map[c - 'A']++;
    }
    int oddCount = 0, index = -1;
    for (int i = 0; i < 26; ++i) {
        if (map[i] & 1) {
            oddCount++;
            index = i;
        }
    }
    if (oddCount > 1 or ((n & 1) ^ (oddCount))) {
        cout << "NO SOLUTION";
    } else {
        for (int i = 0; i < 26; ++i) if (i != index) cout << string(map[i] / 2, 'A' + i);
        if (index != -1) cout << string(map[index], 'A' + index);
        for (int i = 25; i >= 0; --i)  if (i != index) cout << string(map[i] / 2, 'A' + i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}