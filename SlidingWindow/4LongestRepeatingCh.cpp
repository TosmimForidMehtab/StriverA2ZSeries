#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
int characterReplacement(string s, int k) {
	int n = s.size();
	unordered_map<char, int> mp;
	int ans = 0, maxFreq = 0;
	int front = 0, back = 0;
	while (front < n) {
		mp[s[front]]++;
		maxFreq = max(maxFreq, mp[s[front]]);

		while ((front - back + 1) - maxFreq > k) {
			mp[s[back]]--;
			back++;
		}
		ans = max(ans, (front - back + 1));
		front++;
	}
	return ans;
}
// ================= BEST ====================

int32_t main() {
	fast

	int k;
	cin >> k;
	string s;
	cin >> s;
	cout << characterReplacement(s, k);
	cin.get();
}