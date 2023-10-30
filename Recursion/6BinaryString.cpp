#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int countt = 0;
void solve(int n, string& str, vector<string>& ans) {
	if (n == 0) {
		ans.push_back(str);
		countt++;
		return;
	}
	if (str.empty() or str.back() == '0') {
		str.push_back('0');
		solve(n - 1, str, ans);
		str.pop_back();
		str.push_back('1');
		solve(n - 1, str, ans);
		str.pop_back();
	}
	if (str.back() == '1') {
		str.push_back('0');
		solve(n - 1, str, ans);
		str.pop_back();
	}
}

vector<string> generateString(int n) {
	vector<string> ans;
	if (n == 0)
		return ans;

	string str = "";
	solve(n, str, ans);
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<string> ans = generateString(n);
	for (string x : ans)
		cout << x << " ";
	cout << endl;
	cout << countt;
	cin.get();
}