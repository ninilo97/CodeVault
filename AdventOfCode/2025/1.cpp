#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solveTask1() {
	string input;
	int cur = 50, res = 0;
    while (getline(cin, input)) {
		char dir = input[0];
		int offset = stoi(input.substr(1));
		if (dir == 'R') {
			cur = (cur + offset) % 100;
		}
		if (dir == 'L') {
			cur = (cur - offset + 100) % 100;
		}
		if (!cur) res++;
    }
	cout << res << '\n';
}

void solveTask2() {
	string input;
	int cur = 50, res = 0, prev;
    while (getline(cin, input)) {
		char dir = input[0];
		int offset = stoi(input.substr(1));
		prev = cur;
		if (dir == 'R') {
			cur = (cur + offset) % 100;
			res += (prev + offset) / 100;
		}
		if (dir == 'L') {
			cur = ((cur - offset) % 100 + 100) % 100;
			if (prev == 0) res += offset / 100;
			else res += ((100 - prev) + offset) / 100;
		}
    }
	cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	// solveTask1();
	solveTask2();
	return 0;
}