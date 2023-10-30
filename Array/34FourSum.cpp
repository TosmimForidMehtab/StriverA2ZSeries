#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {

		if (i > 0 && nums[i] == nums[i - 1])
			continue;

		for (int j = i + 1; j < nums.size(); j++) {

			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;

			int l = j + 1;
			int r = nums.size() - 1;
			while (l < r) {
				long long sum = nums[i];
				sum += nums[j];
				sum += nums[l];
				sum += nums[r];
				if (sum == target) {
					vector <int> temp = {nums[i], nums[j], nums[l], nums[r]};
					ans.push_back(temp);
					l++;
					r--;
					while (l < r && nums[l] == nums[l - 1])
						l++;
					while (l < r && nums[r] == nums[r + 1])
						r--;
				} else if (sum > target)
					r--;
				else
					l++;
			}
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
	vector<vector<int>> ans = fourSum(arr, 0);
	for (auto i : ans) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	cin.get();
}