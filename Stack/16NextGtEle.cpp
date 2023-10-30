#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
vector<int> nextGreaterElementBrute(vector<int> &nums1, vector<int> &nums2)
{

	int n = nums1.size();
	int m = nums2.size();
	unordered_map<int, int> mp;

	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = i + 1; j < m; j++) {

			if (nums2[i] < nums2[j]) {
				mp[nums2[i]] = nums2[j];
				flag = true;
				break;
			}
		}

		if (!flag)  mp[nums2[i]] = -1;
	}

	for (int i = 0; i < n; i++) {
		if (mp.find(nums1[i]) != mp.end())
			nums1[i] = mp[nums1[i]];
	}
	return nums1;
}
// ================= BETTER ====================
vector<int> nextGreaterElementBetter(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size(), n2 = nums2.size();
	vector<int> ngr(n2);
	stack<int> st;
	for (int i = n2 - 1; i >= 0; i--) {
		while (!st.empty() and st.top() < nums2[i]) st.pop();
		if (st.empty()) ngr[i] = -1;
		else ngr[i] = st.top();
		st.push(nums2[i]);
	}

	unordered_map<int, int> mp;
	for (int i = 0; i < n2; i++) {
		mp[nums2[i]] = ngr[i];
	}

	ngr.clear();
	ngr.resize(n1);

	for (int i = 0; i < n1; ++i)
	{
		if (mp.find(nums1[i]) != mp.end()) ngr[i] = mp[nums1[i]];
	}
	return ngr;
}
// ================= BEST ====================
vector<int> nextGreaterElementBest(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> map;
	stack<int> st;
	for (int num : nums2) {
		while (!st.empty() && st.top() < num) {
			map[st.top()] = num;
			st.pop();
		}
		st.push(num);
	}
	for (int i = 0; i < nums1.size(); i++) {
		nums1[i] = map.count(nums1[i]) ? map[nums1[i]] : -1;
	}
	return nums1;
}
// Codestudio Next Greater to Right
vector<int> NGR(vector<int> &arr, int n) {
	vector<int>ans(n, -1);
	stack<int>st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty()) {
			if (arr[i] < st.top()) {
				ans[i] = st.top();
				break;
			}
			else st.pop();
		}
		st.push(arr[i]);
	}
	return ans;
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	vector<int> arr1(n), arr2(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr1[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> arr2[i];
	}
	vector<int> ans = nextGreaterElementBest(arr1, arr2);
	for (int ele : ans) cout << ele << " ";
	cin.get();
}