#include <bits/stdc++.h>
#include <glpk.h>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> lights;
vector<vector<int>> toggles, joltages;

void processLight(string s) {
	int n = s.size(), toggle = 0;
	for (int i = 0; i < n; ++i) if (s[i] == '#') toggle = toggle | (1 << i);
	lights.emplace_back(toggle);
}

void processToggle(string s) {
	istringstream ss(s);
	string number;
	int toggle = 0;
	while (getline(ss, number, ',')) toggle = toggle | (1 << stoi(number));
	toggles.back().emplace_back(toggle);
}

void processToggles(string s) {
	string number;
	toggles.push_back({});
	auto rbo = s.find("(");
	auto rbc = s.find(")");
	while (rbo != string::npos and rbc != string::npos) {
		processToggle(s.substr(rbo + 1, rbc - rbo - 1));
		s[rbo] = s[rbc] = '*';
		rbo = s.find("(");
		rbc = s.find(")");
	}
}

void processJoltage(string s) {
	joltages.push_back({});
	istringstream ss(s);
	string number;
	while (getline(ss, number, ',')) joltages.back().emplace_back(stoi(number));
}

void processInput() {
	string input;
    while (getline(cin, input)) {
		auto sbo = input.find("[");
		auto sbc = input.find("]");
		processLight(input.substr(sbo + 1, sbc - sbo - 1));

		auto rbo = input.find("(");
		auto rbc = input.rfind(")");
		processToggles(input.substr(rbo, rbc - rbo + 1));
	
		auto cbo = input.find("{");
		auto cbc = input.find("}");
		processJoltage(input.substr(cbo + 1, cbc - cbo - 1));
    }
}

void solveTask1() {
	int n = lights.size(), res = 0;
	for (int i = 0; i < n; ++i) {
		int m = toggles[i].size(), s = (1 << m), minCnt = 1e9;
		for (int j = 0; j < s; ++j) {
			int cur = 0, cnt = 0;
			for (int k = 0; k < m; ++k) {
				if (j & (1 << k)) {
					cnt++;
					cur ^= toggles[i][k];
				}
			}
			if (cur == lights[i]) minCnt = min(minCnt, cnt);
		}
		res += minCnt;
	}
	cout << res << '\n';
}

int findMinimumPresses(vector<int>& toggle, vector<int>& joltage) {
	int n = joltage.size(), m = toggle.size(), result = 0;
	vector<int> rowIndex, columnIndex;
	vector<double> values;
	
	glp_prob* lp = glp_create_prob();
	glp_set_obj_dir(lp, GLP_MIN);
	glp_add_cols(lp, m);
	for (int i = 1; i <= m; ++i) {
		glp_set_col_kind(lp, i, GLP_IV);
		glp_set_col_bnds(lp, i, GLP_LO, 0.0, 0.0);
		glp_set_obj_coef(lp, i, 1.0);
	}
	
	glp_add_rows(lp, n);

	auto add = [&](int i, int j, int k) -> void {
		rowIndex.emplace_back(i);
		columnIndex.emplace_back(j);
		values.emplace_back(k);
	};
	
	add(0, 0, 0);
	for (int i = 1; i <= n; ++i) {
		glp_set_row_bnds(lp, i, GLP_FX, joltage[i - 1], joltage[i - 1]);
		for (int j = 1; j <= m; ++j) {
			if (toggle[j - 1] & (1 << (i - 1))) add(i, j, 1);
		}
	}
	
	glp_load_matrix(lp, rowIndex.size() - 1, rowIndex.data(), columnIndex.data(), values.data());
	
	glp_simplex(lp, NULL);
	glp_intopt(lp, NULL);
	
	if (glp_mip_status(lp) == GLP_OPT) result = round(glp_mip_obj_val(lp));
	glp_delete_prob(lp);
	return result;
}

void solveTask2() {
	int res = 0, n = toggles.size();
	for (int i = 0; i < n; ++i) {
		res += findMinimumPresses(toggles[i], joltages[i]);
	}
	cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif
	processInput();
	solveTask2();
	return 0;
}