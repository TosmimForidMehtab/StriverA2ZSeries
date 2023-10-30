#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Brutforce Approach
int subarraysWithXorK(vector<int> a, int k) {
	int n = a.size();
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int xorr = 0;
		for (int j = i; j < n; j++) {
			xorr = xorr ^ a[j];
			if (xorr == k)
				cnt++;
		}
	}
	return cnt;
}
// Optimal Approach
int subarraysWithXorKOpt(vector<int> a, int k) {
	int n = a.size();
	unordered_map<int, int> mp;
	int xr = 0;
	mp[xr]++;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		xr = xr ^ a[i];

		int x = xr ^ k;
		cnt += mp[x];

		mp[xr]++;
	}
	return cnt;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << subarraysWithXorKOpt(arr, k);
	cin.get();
}