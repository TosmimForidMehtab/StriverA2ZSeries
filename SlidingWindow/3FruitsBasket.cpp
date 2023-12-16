#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Longest contiguous subarray with 2 distinct elemements
// ================= BRUTE ====================

// ================= BETTER ====================
int findMaxFruits(vector<int> &arr, int n) {
	int i = 0, j = 0;
	int maxFruits = INT_MIN;
	unordered_map<int, int> mp;
	while (i < n and j < n) {
		mp[arr[i]]++;

		while (mp.size() > 2) {
			mp[arr[j]]--;
			if (mp[arr[j]] == 0) mp.erase(arr[j]);
			j++;
		}

		maxFruits = max(maxFruits, i - j + 1);
		i++;
	}
	return maxFruits;
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
	cout << findMaxFruits(arr, n);
	cin.get();
}