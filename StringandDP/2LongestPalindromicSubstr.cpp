#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int longestPalindrome(string s) {
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, false));

	int len = 0;

	// Iterate in the dp matrix only on the upper side of the diagonal and traversing diagonal wise
	for (int gap = 0; gap < n; gap++) {
		for (int row = 0, col = gap; col < dp.size(); row++, col++) {
			if (gap == 0)
				dp[row][col] = true;
			else if (gap == 1) {
				if (s[row] == s[col])
					dp[row][col] = true;
			} else {
				if (s[row] == s[col] and dp[row + 1][col - 1])
					dp[row][col] = true;
			}

			if (dp[row][col])
				len = gap + 1;
		}
	}
	return len;
}
// NOTE Ye kya hai, kaisa hai
int Solve(string s, int left, int right) {
	while (left >= 0 && right < s.length() && s[left] == s[right]) {
		left--;
		right++;
	}
	return right - left - 1;
}

string longestPalindromeOpt(string s) {
	int start = 0, end = 0;
	string ans = "";
	int n = s.length();
	for (int i = 0; i < n; i++) {
		int oddAns = Solve(s, i, i);
		int evenAns = Solve(s, i, i + 1);

		int len = max(oddAns, evenAns);

		if (len > end - start) {
			start = i - (len - 1) / 2;
			end = i + (len / 2);
		}
	}

	for (int j = start; j <= end; j++) {
		ans += s[j];
	}
	return ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << longestPalindrome(s);
	cin.get();
}