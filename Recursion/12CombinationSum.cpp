#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void solve(int idx, int sum, int target, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans) {
	if (sum == target) {
		ans.push_back(temp);
		return;
	}
	if (idx >= arr.size() or sum > target) return;

	solve(idx + 1, sum, target, arr, temp, ans);
	sum += arr[idx];
	temp.push_back(arr[idx]);
	solve(idx, sum, target, arr, temp, ans);
	sum -= arr[idx];
	temp.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> temp;
	// Elements in each combination must be in non-decreasing order
	sort(candidates.begin(), candidates.end());
	solve(0, 0, target, candidates, temp, ans);
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
	vector<vector<int>> ans = combinationSum(arr, target);
	for (auto x : ans) {
		for (int &ele : x) cout << ele << " ";
		cout << endl;
	}
	cin.get();
}