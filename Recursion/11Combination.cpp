#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<vector<int>> ans;
void solve(int start, int n, int k, vector<int>&temp) {
	if (k == 0) {
		ans.push_back(temp);
		return;
	}

	if (start > n) return;

	temp.push_back(start);
	solve(start + 1, n, k - 1, temp);
	temp.pop_back();
	solve(start + 1, n, k, temp);
}
vector<vector<int>> combine(int n, int k) {
	vector<int> temp;
	solve(1, n, k, temp);
	return ans;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	vector<vector<int>> ans = combine(n, k);
	for (auto x : ans) {
		for (int &ele : x) cout << ele << " ";
		cout << endl;
	}
	cout << endl;
	cin.get();
}