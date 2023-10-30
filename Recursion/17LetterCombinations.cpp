#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void solve(int idx, string &s, string &temp, vector<string> &ans, vector<string> &mp) {
	if (idx == s.size()) {
		ans.push_back(temp);
		return;
	}
	string str = mp[s[idx] - '0'];
	for (int i = 0; i < str.size(); ++i)
	{
		temp.push_back(str[i]);
		solve(idx + 1, s, temp, ans, mp);
		temp.pop_back();
	}
}
vector<string> letterCombinations(string digits) {
	vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> ans;
	if (digits.size() == 0) return ans;
	string temp;
	solve(0, digits, temp, ans, mp);
	return ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	vector<string> ans = letterCombinations(s);
	for (string x : ans) cout << x << endl;
	cin.get();
}