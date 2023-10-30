#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Leetcode
void solve(int idx, vector<int> &arr, vector<int>&temp, vector<vector<int>> &ans) {
	if (idx == arr.size()) {
		ans.push_back(temp);
		return;
	}
	// Take
	temp.push_back(arr[idx]);
	solve(idx + 1, arr, temp, ans);
	temp.pop_back();

	// Ignore duplicates and not take
	while (idx + 1 < arr.size() and arr[idx] == arr[idx + 1])idx++;
	solve(idx + 1, arr, temp, ans);
}
vector<vector<int>> subsetsWithDup(vector<int>& arr) {
	vector<vector<int>> ans;
	ans.push_back({});
	vector<int> temp;
	sort(arr.begin(), arr.end());
	solve(0, arr, temp, ans);
	return ans;
}
// Codestudio
void solveCS(int idx, vector<int> &arr, vector<int>&temp, vector<vector<int>> &ans) {
	ans.push_back(temp);
	for (int i = idx; i < arr.size(); i++) {
		if (i > idx and arr[i] == arr[i - 1]) continue;
		temp.push_back(arr[i]);
		solveCS(i + 1, arr, temp, ans);
		temp.pop_back();
	}
}

vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
	// Write Your Code Here
	vector<vector<int>> ans;
	vector<int> temp;
	solveCS(0, arr, temp, ans);
	return ans;
}
int32_t main() {
	fast
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<vector<int>> ans = getUniqueSubsets(arr);
	for (auto x : ans) {
		for (int &ele : x) cout << ele << " ";
		cout << endl;
	}
	cout << endl;
	cin.get();
}