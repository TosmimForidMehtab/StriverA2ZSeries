#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void solve(int idx, int target, vector<int> &arr, vector<int>&temp, vector<vector<int>> &ans) {
	if (target == 0) {
		ans.push_back(temp);
		return;
	}
	if (idx >= arr.size() or target < 0) return;

	for (int i = idx; i < arr.size(); i++) {
		if (i > idx and arr[i] == arr[i - 1]) continue;
		if (arr[i] > target) break;

		temp.push_back(arr[i]);
		solve(i + 1, target - arr[i], arr, temp, ans);
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> temp;
	// Elements in each combination must be in non-decreasing order
	sort(candidates.begin(), candidates.end());
	solve(0, target, candidates, temp, ans);
	return ans;
}
int32_t main() {
	fast


	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<vector<int>> res = combinationSum2(arr, target);
	for (auto x : res) {
		for (int &ele : x) cout << ele << " ";
		cout << endl;
	}
	cin.get();
}