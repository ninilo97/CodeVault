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

vector<long long> getShapeCount(string s) {
	auto x = s.find(' ');
	s = s.substr(x + 1);
	istringstream ss(s);
	string token;
	vector<long long> res;
	while (getline(ss, token, ' ')) {
		res.emplace_back(stoi(token));
	}

	return res;
}

long long getRegionArea(string& s) {
	auto x = s.find(':');
	s = s.substr(0, x);
	istringstream ss(s);
	string token;
	vector<long long> res;
	while (getline(ss, token, 'x')) {
		res.emplace_back(stoi(token));
	}
	return res[0] * res[1];
}

void solveTask1(vector<string> inputs) {
	vector<int> areaOfShape(6, 0);
	for (int i = 0; i < 6; ++i) {
		for (int j = 1; j <= 3; ++j) {
			areaOfShape[i] += count_if(inputs[i * 5 + j].begin(), inputs[i * 5 + j].end(), [&](char& c){ return c == '#'; });
		}
	}
	int res = 0;
	for (int i = 30; i < inputs.size(); ++i) {
		vector<long long> shapeCount = getShapeCount(inputs[i]);
		long long minimumUsedArea = 0, regionArea = getRegionArea(inputs[i]);
		for (int j = 0; j < 6; ++j) {
			minimumUsedArea += areaOfShape[j] * shapeCount[j];
		}
		if (regionArea < minimumUsedArea) {
			continue;
		}
		res++;
	}
	cout << res << '\n';
}

void solveTask2(vector<string> inputs) {
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	solveTask1(processInput());
	solveTask2(processInput());
	return 0;
}