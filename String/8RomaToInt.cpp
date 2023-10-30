#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int romanToInt(string s) {
	int n = s.size();
	unordered_map<char, int> mp;
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i < n - 1 and mp[s[i + 1]] > mp[s[i]])
			ans -= mp[s[i]];
		else
			ans += mp[s[i]];
	}

	return ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << romanToInt(s);
	cin.get();
}