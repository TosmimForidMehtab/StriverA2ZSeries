#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(vector<int>& arr, int mid, int k) {
	int sum = 0, part = 1;
	for (int i = 0; i < arr.size(); i++) {
		if (sum + arr[i] > mid) {
			part++;
			sum = arr[i];
		} else
			sum += arr[i];
	}
	return part <= k;
}
int largestSubarraySumMinimized(vector<int> a, int k) {
	int maxEle = *max_element(a.begin(), a.end());
	int sumEle = 0;
	sumEle = accumulate(a.begin(), a.end(), sumEle);

	int low = maxEle, high = sumEle;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(a, mid, k))
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << largestSubarraySumMinimized(arr, k);
	cin.get();
}