#include<bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
/*Generate all subarrays and check for min and max ele to find the difference and add them up*/
long long subArrayRangesBrute(vector<int>& nums) {
	int n = nums.size();
	long long res = 0;
	for (int i = 0; i < n - 1; i++) {
		int maxi = nums[i], mini = nums[i];
		for (int j = i + 1; j < n; j++) {
			if (nums[j] > maxi)maxi = nums[j];
			else if (nums[j] < mini)mini = nums[j];
			res += maxi - mini;
		}
	}
	return res;
}
// ================= BETTER ====================
stack<int> st;
vector<int> NSL(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n, -1);
	for (int i = 0; i < n ; ++i)
	{
		while (!st.empty() and arr[i] < arr[st.top()]) st.pop();
		if (!st.empty()) ans[i] = st.top();
		st.push(i);
	}
	return ans;
}
vector<int> NSR(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n, n);
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and arr[i] <= arr[st.top()]) st.pop();
		if (!st.empty()) ans[i] = st.top();
		st.push(i);
	}
	return ans;
}
vector<int> NGL(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n, -1);
	for (int i = 0; i < n ; ++i)
	{
		while (!st.empty() and arr[i] >= arr[st.top()]) st.pop();
		if (!st.empty()) ans[i] = st.top();
		st.push(i);
	}
	return ans;
}
vector<int> NGR(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n, n);
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and arr[i] > arr[st.top()]) st.pop();
		if (!st.empty()) ans[i] = st.top();
		st.push(i);
	}
	return ans;
}
void clearSt() {
	while (!st.empty()) st.pop();
}
long long subArrayRangesBett(vector<int>& arr) {
	int n = arr.size();
	vector<int> nsl = NSL(arr);
	clearSt();
	vector<int> nsr = NSR(arr);
	clearSt();
	vector<int> ngl = NGL(arr);
	clearSt();
	vector<int> ngr = NGR(arr);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		long long leftMin = i - nsl[i], rightMin = nsr[i] - i;
		long long leftMax = i - ngl[i], rightMax = ngr[i] - i;

		sum += (leftMax * rightMax - leftMin * rightMin) * arr[i];
	}
	return sum;
}
// ================= BEST ====================

int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << subArrayRangesBett(arr);
	cin.get();
}