#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<long long, long long>> processInput() {
	string input; cin >> input;

	istringstream ss(input);
    string token;

    vector<pair<long long, long long>> parts;
    while (getline(ss, token, ',')) {
		auto x = token.find('-');
        parts.emplace_back(stoll(token.substr(0, x)), stoll(token.substr(x + 1)));
    }
	sort(parts.begin(), parts.end());
	for (auto& [f, s] : parts) cout << f << ' ' << s << '\n';
	return parts;
}

long long process1First(long long num) {
	string s = to_string(num);
	if (s.size() & 1) return powl(10, s.size() / 2);
	return stoll(s.substr(0, s.size() / 2));
}

long long process1Last(long long num) {
	string s = to_string(num);
	if (s.size() & 1) return powl(10, s.size() / 2) - 1;
	return stoll(s.substr(0, s.size() / 2));
}

long long process1(long long n1, long long n2) {
	long long first = process1First(n1), last = process1Last(n2), res = 0;
	for (long long i = first; i <= last; ++i) {
		long long x = i * powl(10, to_string(i).size()) + i;
		if (x < n1) continue;
		if (x > n2) break;
		res += x;
	}
	return res;
}

long long process2(vector<long long>& numbers, long long n1, long long n2) {
	long long res = 0;
	for (auto start = lower_bound(numbers.begin(), numbers.end(), n1); start != numbers.end(); start++) {
		if (*start > n2) break;
		res = (res + *start);
	}
	return res;
}

void solveTask1(vector<pair<long long, long long>> input) {
	long long res = 0;
	for (auto& [f, s] : input) {
		res += process1(f, s);
	}
	cout << res << '\n';
}

const long long MX = 10000000000LL;

void solveTask2(vector<pair<long long, long long>> input) {
	vector<long long> numbers;
	for (long long i = 1; i <= 100000; ++i) {
		bool first = true;
		for (long long num = i, len = to_string(i).size(), power  = pow(10, len); num < MX; num = num * power + i) {
			if (first) {
				first = false;
				continue;
			}
			numbers.emplace_back(num);
		}
		// cout << i << ' ' << numbers.size() << '\n';
	}
	sort(numbers.begin(), numbers.end());
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
	// for (auto& x : numbers) cout << x << '\n';
	long long res = 0;
	for (auto& [f, s] : input) {
		res += process2(numbers, f, s);
	}
	cout << res << '\n';
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