#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) // Avoiding duplicates
			continue;
		int l = i + 1, r = nums.size() - 1;
		while (l < r) {
			if (nums[i] + nums[l] + nums[r] == 0) {
				ans.push_back({ nums[i], nums[l], nums[r] });
				while (l < r && nums[l] == nums[l + 1]) // Avoiding duplicates
					l++;
				while (l < r && nums[r] == nums[r - 1]) // Avoiding duplicates
					r--;
				l++, r--;
			} else if (nums[i] + nums[l] + nums[r] > 0)
				r--;
			else
				l++;
		}
	}
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<vector<int>> ans = threeSum(arr);
	for (auto i : ans) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	cin.get();
}