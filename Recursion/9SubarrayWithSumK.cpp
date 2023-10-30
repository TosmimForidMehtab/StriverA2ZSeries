#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
vector<vector<int>> subarraysWithSumK1(vector<int> a, long long target) {
	vector<vector<int>> ans;
	int n = a.size();
	for (int i = 0; i < n; ++i)
	{
		long long sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum == target) {
				ans.push_back(vector<int>(a.begin() + i, a.begin() + j + 1));
			}
		}
	}
	return ans;
}
// Recursive
void findSubarraysWithSumRec(const vector<int>& nums, int k, int start, vector<int>& current, vector<vector<int>>& result) {
	if (start == nums.size()) {
		return;
	}

	current.push_back(nums[start]);

	int sum = 0;
	for (int i = 0; i < current.size(); ++i) {
		sum += current[i];
	}

	if (sum == k) {
		result.push_back(current);
	}

	findSubarraysWithSumRec(nums, k, start + 1, current, result);
	current.pop_back();
	findSubarraysWithSumRec(nums, k, start + 1, current, result);
}

vector<vector<int>> findSubarraysWithSum(const vector<int>& nums, int k) {
	vector<vector<int>> result;
	vector<int> current;
	findSubarraysWithSumRec(nums, k, 0, current, result);
	return result;
}
// ================= BEST ====================
vector<vector<int>> subarraysWithSumK(vector<int> &a, long long k) {
	vector<vector<int>> ans;
	int n = a.size();
	unordered_map<long long, int> mp;
	long long sum = 0;
	mp[sum] = -1;
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
		if (mp.find(sum - k) != mp.end()) {
			// cout << mp[sum - k] << " " << i << endl;
			int st = mp[sum - k] + 1;
			/*for (int j = st; j <= i; j++) cout << a[j] << " ";
			cout << endl;*/
			ans.push_back(vector<int>(a.begin() + st, a.begin() + i + 1));
		}
		mp[sum] = i;
	}
	return ans;
}
// Leetcode
int subarraySum(vector<int>& nums, int k) {
	int n = nums.size();
	int currSum = 0;
	int count = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	{
		currSum += nums[i];
		if ((currSum - k) == 0) {
			count++;
		}
		if (mp.find(currSum - k) != mp.end()) {
			count += mp[currSum - k];
		}
		mp[currSum]++;
	}
	return count;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	long long target;
	cin >> target;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<vector<int>> ans = subarraysWithSumK(arr, target);
	for (auto i : ans) {
		for (int &j : i) cout << j << " ";
		cout << endl;
	}
	cin.get();
}