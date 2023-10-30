#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int getLongestZeroSumSubarrayLength(vector<int>& arr) {
	int n = arr.size();
	unordered_map<int, int> mp;
	int sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == 0) {
			ans = i + 1;
		} else {
			if (mp.find(sum) != mp.end()) {
				ans = max(ans, i - mp[sum]);
			} else
				mp[sum] = i;
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
	cout << getLongestZeroSumSubarrayLength(arr);
	cin.get();
}