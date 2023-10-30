#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

// ================= BETTER (TLE)====================
bool solve(int idx, int n, int k, vector<int> &a, long long sum) {
	if (sum > k) return false;
	if (sum == k) return true;
	if (idx >= n) return false;

	if (solve(idx + 1, n, k, a, sum)) return true;
	if (solve(idx + 1, n, k, a, sum + a[idx])) return true;
	return false;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
	long long sum = 0;
	return solve(0, n, k, a, sum);
}
// ================= BEST (DP)====================
vector<vector<int>> dp;
bool solve(vector<int>& arr, int k, int idx) {
	if (k == 0) {
		return true;
	}
	if (idx == arr.size() or k < 0) {
		return false;
	}
	if (dp[idx][k] != -1) {
		return dp[idx][k];
	}
	bool include = solve(arr, k - arr[idx], idx + 1);
	bool exclude = solve(arr, k, idx + 1);
	dp[idx][k] = include or exclude;
	return dp[idx][k];
}

bool isSubsetPresentOpt(int n, int k, vector<int> &a)
{
	dp.assign(n, vector<int>(k + 1, -1));
	return solve(a, k, 0);
}
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << isSubsetPresentOpt(n, k, arr);
	cin.get();
}