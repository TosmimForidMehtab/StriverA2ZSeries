#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isAnagram(string s, string t) {
	int n = s.length();
	int m = t.length();
	if (n != m)
		return false;
	unordered_map<char, int> mp;
	for (int i = 0; i < n; i++) {
		mp[s[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (mp.find(t[i]) == mp.end())
			return false;
		mp[t[i]]--;
		if (mp[t[i]] == 0)
			mp.erase(t[i]);
	}
	return mp.empty();
}
int32_t main() {
	fast
    cout.setf(ios::boolalpha);

	string s, t;
	cin >> s >> t;
	cout << isAnagram(s,t);
	cin.get();
}