#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// O(n) + O(mp.size), O(n)
vector<int> majorityElement1(vector<int>& nums) {
	int n = nums.size();
	int x = n / 3;
	unordered_map<int, int> mp;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		mp[nums[i]]++;
	}
	for (auto i : mp) {
		if (i.second > x) {
			ans.push_back(i.first);
		}
	}
	return ans;
}
// O(n), O(n)
vector<int> majorityElement2(vector<int>& nums) {
	int n = nums.size();
	vector<int> ans;
	unordered_map<int, int> mp;
	int minVal = n / 3;
	for (int i = 0; i < n; i++) {
		mp[nums[i]]++;
		if (mp[nums[i]] > minVal) {
			if (!ans.empty() and ans[ans.size() - 1] != nums[i])
				ans.push_back(nums[i]);
			else if (ans.empty())
				ans.push_back(nums[i]);
		}
		if (ans.size() == 2)
			break;
	}
	sort(ans.begin(), ans.end());
	return ans;
}
// Optimised. Boyer Moore Algo
vector<int> majorityElement(vector<int>& nums) {
	int num1 = INT_MIN, num2 = INT_MIN;
	int count1 = 0, count2 = 0;
	for (auto element : nums) {
		if (num1 == element) {
			count1++;
		} else if (num2 == element) {
			count2++;
		} else if (count1 == 0) {
			num1 = element;
			count1 = 1;
		} else if (count2 == 0) {
			num2 = element;
			count2 = 1;
		} else {
			count1--;
			count2--;
		}
	}
	vector<int> output;
	int countMajority = nums.size() / 3;
	count1 = 0, count2 = 0;
	for (auto element : nums) {
		if (num1 == element) {
			count1++;
		}
		if (num2 == element) {
			count2++;
		}
	}
	if (count1 > countMajority) {
		output.push_back(num1);
	}
	if (count2 > countMajority) {
		output.push_back(num2);
	}
	return output;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ans = majorityElement(arr);
	for (int i : ans)
		cout << i << " ";
	cin.get();
}