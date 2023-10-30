#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int maxDepth(string s) {
	int cnt = 0, ans = 0;
	for (char ch : s) {
		if (ch == '(')
			cnt++;
		if (ch == ')')
			cnt--;
		ans = max(ans, cnt);
	}
	return ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << maxDepth(s);
	cin.get();
}