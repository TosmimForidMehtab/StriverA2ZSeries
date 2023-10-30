#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
/*Generate all subarrays and find ans sum the minimum from them*/
// ================= BETTER ====================

// ================= BEST ====================
const int MOD = 1e9 + 7;
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
int sumSubarrayMins(vector<int>& arr) {
	int n = arr.size();
	vector<int> nsl = NSL(arr);
	while (!st.empty()) st.pop();
	vector<int> nsr = NSR(arr);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int numOfEleLeft = i - nsl[i];
		int numOfEleRight = nsr[i] - i;

		long long totalEle = numOfEleLeft * numOfEleRight;
		long long totalSum = arr[i] * totalEle;

		sum = (sum + totalSum) % MOD;
	}
	return (int)sum;
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
	cout << sumSubarrayMins(arr);
	cin.get();
}