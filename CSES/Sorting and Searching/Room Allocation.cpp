#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<tuple<int, int, int>> logs;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        logs.emplace_back(i, x, 1);
        logs.emplace_back(i, y, 0);
    }
    sort(logs.begin(), logs.end(), [&](tuple<int, int, int>& a, tuple<int, int, int>& b) -> bool {
        return get<1>(a) == get<1>(b) ? get<2>(a) > get<2>(b) : get<1>(a) < get<1>(b);
    });
    int currentMax = 0;
    unordered_set<int> available;
    vector<int> assignedRoom(n, -1);
    for (auto& [customer, time, checkin] : logs) {
        if (checkin) {
            if (available.empty()) available.insert(++currentMax);
            auto x = available.begin();
            assignedRoom[customer] = *x;
            available.erase(x);
        } else {
            available.insert(assignedRoom[customer]);
        }
    }
    cout << currentMax << '\n';
    for (auto& x : assignedRoom) cout << x << ' '; cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
	return 0;
}