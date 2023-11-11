#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
// Generate all substrings and for each substring, check if it has unique characters and update the ans with its length accordingly
// ================= BETTER ====================
// O(2N), O(N)
int longestSubstr(string &s) {
	int n = s.length();
	if (n == 0) return 0;
	int i = 0, j = 0, maxLen = 0;
	unordered_set<char> st;
	while (i < n) {
		while (st.find(s[i]) != st.end()) {
			st.erase(s[j]);
			j++;
		}
		st.insert(s[i]);
		maxLen = max(maxLen, i - j + 1);
		i++;
	}
	return maxLen;
}
// ================= BEST ====================
int lengthOfLongestSubstring(string &s) {
	unordered_map < char, int > mp;

	int start = 0, end = 0;
	int maxLen = 0;

	while (end < s.size()) {
		char c = s[end];

		if (mp.find(c) != mp.end()) {
			start = max(start, mp[c] + 1);
		}

		maxLen = max(maxLen, end - start + 1);

		mp[c] = end;
		end++;
	}
	return maxLen;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << longestSubstr(s);
	cin.get();
}