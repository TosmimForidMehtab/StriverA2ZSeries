#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void solve(int k, int n, int start, vector<int> &temp, vector<vector<int>>&ans) {
	if (k == 0) {
		if (n == 0) {
			ans.push_back(temp);
		}
		return;
	}

	if (start > 9 or k > n) return;

	// Take
	temp.push_back(start);
	solve(k - 1, n - start, start + 1, temp, ans);
	temp.pop_back();
	// Not take
	solve(k, n, start + 1, temp, ans);
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> ans;
	vector<int> temp;
	solve(k, n, 1, temp, ans);
	return ans;
}
int32_t main() {
	fast

	int n, k;
	cin >> k >> n;
	vector<vector<int>> ans = combinationSum3(k, n);
	for (auto x : ans) {
		for (int &ele : x) cout << ele << " ";
		cout << endl;
	}
	cin.get();
}