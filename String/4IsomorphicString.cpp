#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isIsomorphic(string s, string t) {
	int n = s.length();
	int m = t.length();
	if (n != m)
		return false;

	unordered_map<char, char> mp1, mp2;

	for (int i = 0; i < n; i++) {
		if (mp1[s[i]] and mp1[s[i]] != t[i])
			return false;
		if (mp2[t[i]] and mp2[t[i]] != s[i])
			return false;

		mp1[s[i]] = t[i];
		mp2[t[i]] = s[i];
	}
	return true;
}
// TODO: Use one map
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	string s, t;
	cin >> s >> t;
	cout << isIsomorphic(s, t);
	cin.get();
}