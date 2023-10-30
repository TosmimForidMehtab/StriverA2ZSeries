#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

vector<int> topK(vector<int>& nums, int k) {
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
	}

	vector<pair<int, int>> v;
	for (auto x : mp)
		v.push_back(x);

	sort(v.begin(), v.end(), cmp);

	vector<int> ans;
	for (int i = 0; i < k; i++) {
		ans.push_back(v[i].first);
	}

	return ans;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ans = topK(arr, k);
	for (int ele : ans)
		cout << ele << " ";
	cin.get();
}