#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int palindromicSubstr(string s) {
	int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n, false));

	int countt = 0;

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
				countt++;
		}
	}
	return countt;
}

// NOTE Ye kya hai, kaise hai
int countSubstrings(string s) {
	int n = s.size();
	if (n == 0 or n == 1)
		return n;

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int j = i, k = i;
		while (j >= 0 and k < n and s[j] == s[k]) {
			j--;
			k++;
			cnt++;
		}

		// For even
		j = i, k = i + 1;
		while (j >= 0 and k < n and s[j] == s[k]) {
			j--;
			k++;
			cnt++;
		}
	}

	return cnt;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << palindromicSubstr(s);
	cin.get();
}