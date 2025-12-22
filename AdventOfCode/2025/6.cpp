#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<string> splitBySpace(string& input) {
	vector<string> words;
    istringstream iss(input);
    string word;

    while (iss >> word) words.push_back(word);
    return words;
}

vector<vector<string>> processInput1() {
	string input, part;
	vector<vector<string>> inputs;
    while (getline(cin, input)) {
		inputs.emplace_back(splitBySpace(input));
    }
	return inputs;
}

vector<string> processInput2() {
	string input, prev, part;
	vector<string> inputs;
    while (getline(cin, input)) {
		inputs.push_back(input);
    }
	return inputs;
}

void solveTask1(vector<vector<string>> inputs) {
	long long n = inputs[0].size(), m = inputs.size();
	vector<long long> res(n, 0);
	for (int i = 0; i < n; ++i) {
		bool isAdd = inputs[m - 1][i] == "+";
		res[i] = !isAdd;
		for (int j = 0; j < m - 1; ++j) {
			if (isAdd) res[i] += stoll(inputs[j][i]);
			else res[i] *= stoll(inputs[j][i]);
		}
	}
	cout << accumulate(res.begin(), res.end(), 0LL) << '\n';
}

void solveTask2(vector<string> inputs) {
	long long n = inputs[0].size(), m = inputs.size(), res = 0;
	for (ll start = 0; start < n; ) {
		ll end = start + 1;
		while (end < n and inputs[m - 1][end] == ' ') end++;
		if (end == n) end++;
		vector<ll> nums;
		for (ll i = start; i < end - 1; ++i) {
			ll num = 0;
			for (ll j = 0; j < m; ++j) {
				if (!isdigit(inputs[j][i])) {
					if (num) break;
					else continue;
				}
				num = num * 10 + inputs[j][i] - '0';
			}
			nums.emplace_back(num);
		}
		bool isAdd = inputs[m - 1][start] == '+';
		ll tmp = isAdd ? accumulate(nums.begin(), nums.end(), 0LL) : accumulate(nums.begin(), nums.end(), 1LL, multiplies<ll>());

		res += tmp;
		start = end;
	}
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