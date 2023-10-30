#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
// ================= BETTER ====================
// Step 1: Check paindrome for current string
// Step 2: If palindrome, add to answer and recurse for i+1 substrings
// One TC failing in codestudio
bool isPalindrome(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

void solve(string &s, vector<string> &temp, vector<vector<string>> &ans) {
	if (s.length() == 0) {
		ans.push_back(temp);
		return;
	}

	for (int i = 0; i < s.length(); i++) {
		if (isPalindrome(curr)) {
			temp.push_back(curr);
			solve(ros, temp, ans);
			temp.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	vector<vector<string>> ans;
	vector<string> temp;
	solve(s, temp, ans);
	return ans;
}

bool isPalindromeAlt(string s, int start, int end) {
	while (start <= end) {
		if (s[start++] != s[end--]) return false;
	}
	return true;
}

void solveAlt(int idx, string &s, vector<string> &temp, vector<vector<string>> &ans) {
	if (idx == s.length()) {
		ans.push_back(temp);
		return;
	}

	for (int i = idx; i < s.length(); i++) {
		string curr = s.substr(0, i + 1);
		string ros = s.substr(i + 1);
		if (isPalindromeAlt(curr, idx, i)) {
			temp.push_back(s.substr(idx, i - idx + 1));
			solveAlt(i + 1, s, temp, ans);
			temp.pop_back();
		}
	}
}
vector<vector<string>> partitionAlt(string s) {
	vector<vector<string>> ans;
	vector<string> temp;
	solveAlt(0, s, temp, ans);
	return ans;
}
// ================= BEST ====================

int32_t main() {
	fast

	string s;
	cin >> s;
	vector<vector<string>> ans = partitionAlt(s);
	for (auto x : ans) {
		for (string &ele : x) cout << ele << " ";
		cout << endl;
	}
	cin.get();
}