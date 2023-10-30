#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> twoSum(const vector<int>& nums, int target) {
	int n = nums.size();
	vector<int> ans;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (mp.find(target - nums[i]) != mp.end()) {
			ans.push_back(mp[target - nums[i]]);
			ans.push_back(i);
		}
		mp[nums[i]] = i;
	}
	return ans;
}

// GFG
vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X) {
    
}
int32_t main() {
	fast

	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ans = twoSum(arr, target);
	for (int x : ans)
		cout << x << " ";
	cin.get();
}