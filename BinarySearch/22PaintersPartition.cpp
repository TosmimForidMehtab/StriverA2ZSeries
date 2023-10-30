#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(const vector<int>& arr, int mid, int k) {
	int painter = 1, block = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (block + arr[i] > mid) {
			painter++;
			block = arr[i];
		} else
			block += arr[i];
	}
	return painter <= k;
}
int findLargestMinDistance(vector<int>& boards, int k) {
	int maxEle = *max_element(boards.begin(), boards.end());
	int sumEle = 0;
	sumEle = accumulate(boards.begin(), boards.end(), sumEle);

	int low = maxEle, high = sumEle;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(boards, mid, k))
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
	cout << findLargestMinDistance(arr,k);
	cin.get();
}