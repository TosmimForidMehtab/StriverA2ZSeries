#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ==================== Most Optimized Leetcode==================
vector<vector<int>> subsetsOpt(vector<int>& nums) {
	int n = nums.size();
	int num_of_subsets = (1 << n);
	vector<vector<int>> subsets;
	for (int mask = 0; mask < num_of_subsets; mask++) {
		vector<int> subset;
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) != 0) {
				subset.push_back(nums[i]);
			}
		}
		subsets.push_back(subset);
	}
	return subsets;
}
// ==================== Most Optimised Codestudio =================
vector<string> generateSubsequencesOpt(string s)
{
	// Write your code here.
	int n = s.size();
	int num_of_subsets = (1 << n);
	vector<string> subsets;
	for (int mask = 0; mask < num_of_subsets; mask++) {
		string subset;
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) != 0) {
				subset.push_back(s[i]);
			}
		}
		subsets.push_back(subset);
	}
	return subsets;

}
// =================== Leetcode ========================
vector<vector<int>> ans;
void solve(vector<int>& nums, vector<int>subset , int idx) {
	if (idx >= nums.size()) {
		ans.push_back(subset);
		return;
	}
	solve(nums, subset, idx + 1);
	subset.push_back(nums[idx]);
	// subset.pop_back();
	solve(nums, subset, idx + 1);
}
vector<vector<int>> generateSubsets(vector<int> &nums) {
	vector<int> subset;
	solve(nums, subset, 0);
	return ans;
}
// ======================== Codestudio ====================
void generate(string &s, string &res, vector<string> &ans, int idx) {
	if (idx == s.size()) {
		ans.push_back(res);
		return;
	}

	res.push_back(s[idx]);
	generate(s, res, ans, idx + 1);
	res.pop_back();
	generate(s, res, ans, idx + 1);
}
vector<string> generateSubsequences(string s)
{
	// Write your code here.
	vector<string> ans;
	string res = "";
	generate(s, res, ans, 0);
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> ans = generateSubsequences(s);
	for (string x : ans) cout << x << " ";
	cin.get();
}