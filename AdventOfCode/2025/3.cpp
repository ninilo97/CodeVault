#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<string> processInput() {
	string input;
	vector<string> inputs;
    while (getline(cin, input)) {
		inputs.emplace_back(input);
    }
	return inputs;
}

void solveTask1(vector<string> banks) {
	int n = banks.size();
	long long res = 0;
	for (auto& bank : banks) {
		vector<long long> biggest(12, 0);
		for (auto& c : bank) {
			long long num = c - '0';
			for (int k = 11; k > 0; --k) {
				if (biggest[k - 1]) biggest[k] = max(biggest[k], (biggest[k - 1] * 10LL) + num);
			}
			biggest[0] = max(biggest[0], num);
		}
		res += *max_element(biggest.begin(), biggest.end());
	}
	cout << res << '\n';
}

void solveTask2() {
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	solveTask1(processInput());
	// solveTask2(processInput());
	return 0;
}