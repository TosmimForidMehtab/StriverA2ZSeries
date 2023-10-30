#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(vector<int>& arr, int mid, int h) {
	int hours = 0;
	for (int& x : arr) {
		hours += x / mid;
		if (x % mid != 0)
			hours++;
	}
	return hours <= h;
}
// Koko har ek ghante mei ek piles se banana kha sakta hai
// Min kitna banana har ghante mei khana hoga taki woh saara bananas kha paye
int minEatingSpeed(vector<int>& piles, int h) {
	int maxEle = *max_element(piles.begin(), piles.end());
	int low = 1, high = maxEle;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(piles, mid, h)) {
			high = mid - 1;
		} else
			low = mid + 1;
	}
	return low;
}
int32_t main() {
	fast

	int n, h;
	cin >> n >> h;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << minEatingSpeed(arr, h);
	cin.get();
}