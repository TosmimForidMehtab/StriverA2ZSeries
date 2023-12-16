#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
int numSubarraysWithSum(vector<int>& nums, int goal) {
	int n = nums.size(), i = 0;
	int sum = 0, cnt = 0;
	unordered_map<int, int> mp;
	mp[0] = 1;
	while (i < n) {
		sum += nums[i];
		if (mp.count(sum - goal)) cnt += mp[sum - goal];
		mp[sum]++;
		i++;
	}
	return cnt;
}
int solve(vector<int> &arr, int k)
{
	if (k < 0) return 0;
	int l = 0, r = 0, sum = 0, res = 0;
	while (r < arr.size())
	{
		sum += arr[r];
		while (sum > k)
		{
			sum -= arr[l];
			l++;
		}
		res += r - l + 1;
		r++;
	}
	return res;
}

int subarrayWithSum(vector<int> &arr, int k) {
	return solve(arr, k) - solve(arr, k - 1);
}
// =========================BEST==========================
int subarrayWithSumBest(vector<int>&arr, int k) {
	int res = 0;
	int cnt = 0;
	vector<int> prefix(arr.size() + 1, 0);
	prefix[0] = 1;
	for (int i = 0; i < arr.size(); i++) {
		cnt += arr[i];
		if (cnt >= k) {
			res += prefix[cnt - k];
		}
		prefix[cnt]++;
	}
	return res;
}
int32_t main() {
	fast

	int n, goal;
	cin >> n >> goal;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << numSubarraysWithSum(arr, goal);
	cin.get();
}