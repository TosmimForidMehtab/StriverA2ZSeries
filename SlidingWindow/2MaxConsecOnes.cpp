#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= Max consec Ones 1 ====================
int findMaxConsecutiveOnes(vector<int>& nums) {
	int currSum = 0, maxSum = 0;
	int n = nums.size();
	for (int i = 0; i < n; ++i)
	{
		currSum += nums[i];
		maxSum = max(maxSum, currSum);
		if (nums[i] < 1) currSum = 0;
	}
	return maxSum;
}
// ================= Max consecutive ones with max 1 replacement ====================
int findMaxConsecutiveOnes2(vector<int>& nums) {
	int ans = 0, cnt = 0;
	int j = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0) cnt++;
		while (cnt > 1) {
			j++;
			if (nums[j] == 0) cnt--;
		}

		int len = i - j;
		if (len > ans) ans = len;
	}
	return ans;
}
// ================= Max consecutive ones with max k replacement  ====================
int longestOnes3(vector<int>& nums, int k) {
	int ans = 0, cnt = 0;
	int j = -1;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 0) cnt++;
		while (cnt > k) {
			j++;
			if (nums[j] == 0) cnt--;
		}

		int len = i - j;
		if (len > ans) ans = len;
	}
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
	cout << longestOnes3(arr, 2);
	cin.get();
}