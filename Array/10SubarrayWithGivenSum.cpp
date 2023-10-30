#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Leetcode: Returns the count
int lenOfLongSubarrLeet(int arr[],  int n, int k) {
	int sum = 0, ans = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == k)
			ans++;
		if (mp.find(sum - k) != mp.end())
			ans += mp[sum - k];
		mp[sum]++;
	}
	return ans;
}

int lenOfLongSubarr(int arr[], int n, int k) {
	int sum = 0, ans = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == k)
			ans = max(ans, i + 1);
		if (mp.find(sum - k) != mp.end()) {
			ans = max(ans, i - mp[sum - k]);
		}
		if (mp.find(sum) == mp.end()) {
			mp[sum] = i;
		}
	}
	return ans;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << lenOfLongSubarr(arr, n, k);
	cin.get();
}