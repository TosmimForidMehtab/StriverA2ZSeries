#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(vector<int>& arr, int mid, int days) {
	int possibleDays = 1;
	long long sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > mid)
			return false;
		if (arr[i] + sum <= mid)
			sum += arr[i];
		else {
			possibleDays++;
			sum = arr[i];
		}
	}
	return possibleDays <= days;
}
int shipWithinDays(vector<int>& weights, int days) {
	long long sum = 0;
	sum = accumulate(weights.begin(), weights.end(), sum);
	int low = 1, high = sum;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(weights, mid, days))
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}
int32_t main() {
	fast

	int n, days;
	cin >> n >> days;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << shipWithinDays(arr, days);
	cin.get();
}