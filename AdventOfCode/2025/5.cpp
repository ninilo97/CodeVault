#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


vector<pair<ll, ll>> processInput1() {
	bool empty = false;
	string input;
	vector<pair<ll, ll>> inputs;
    while (getline(cin, input)) {
		if (input.empty()) {
			empty = 1;
			continue;
		}
		if (empty) {
			inputs.emplace_back(stoll(input), 0);
		} else {
			auto x = input.find('-');
			ll a = stoll(input.substr(0, x));
			ll b = stoll(input.substr(x + 1));
			inputs.emplace_back(a, 1);
			inputs.emplace_back(b + 1, -1);
		}
    }
	sort(inputs.begin(), inputs.end());
	return inputs;
}


vector<pair<ll, ll>> processInput2() {
	string input;
	vector<pair<ll, ll>> inputs;
    while (getline(cin, input)) {
		if (input.empty()) break;
		auto x = input.find('-');
		ll a = stoll(input.substr(0, x));
		ll b = stoll(input.substr(x + 1));
		inputs.emplace_back(a, b);
    }
	sort(inputs.begin(), inputs.end());
	return inputs;
}

void solveTask1(vector<pair<ll, ll>> inputs) {
	long long n = inputs.size(), res = 0;
	cout << res << '\n';
}

void solveTask2(vector<pair<ll, ll>> inputs) {
	long long n = inputs.size(), res = 0;
	for (int i = 1; i < n; ++i) {
		if (inputs[i].first <= inputs[i - 1].second) {
			inputs[i].first = min(inputs[i].first, inputs[i - 1].first);
			inputs[i].second = max(inputs[i].second, inputs[i - 1].second);
			inputs[i - 1] = {0, -1};
		}
	}
	for (auto& [f, s] : inputs) res += s - f + 1;
	cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	// solveTask1(processInput1());
	solveTask2(processInput2());
	return 0;
}