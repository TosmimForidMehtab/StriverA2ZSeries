#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int findAllSubarraysWithGivenSum(vector < int >& arr, int k) {
	// Write Your Code Here
	int n = arr.size();
	int ans = 0, sum = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == k) {
			ans++;
		} else if (sum > k) {
			while (sum > k)
				sum -= arr[j++];

			if (sum == k)
				ans++;
		}
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
	cout << findAllSubarraysWithGivenSum(arr, k);
	cin.get();
}