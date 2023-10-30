#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<string>result;
void solve(int open, int close, int n, string current) {
	if (current.length() == n * 2) {
		result.push_back(current);
		return;
	}
	if (open < n)
		solve(open + 1, close, n, current + "(");
	if (close < open)
		solve(open, close + 1, n, current + ")");
}
//* Better than the above
void generate(string& ans, int open, int close) {
	if (open == 0 and close == 0) {
		result.push_back(ans);
		return;
	}

	if (open > 0) {
		ans.push_back('(');
		generate(ans, open - 1, close);
		ans.pop_back();
	}

	if (close > 0) {
		if (close > open) { // This condition takes care of invalid parenthesis
			ans.push_back(')');
			generate(ans, open, close - 1);
			ans.pop_back();
		}
	}
}
vector<string> generateParenthesis(int n) {
	// solve(0, 0, n, "");

	string ans = "";
	generate(ans, n, n);
	return result;
}
int32_t main() {
	fast

	int n; cin >> n;
	vector<string> ans = generateParenthesis(n);
	for (string x : ans)
		cout << x << " ";
	cin.get();
}