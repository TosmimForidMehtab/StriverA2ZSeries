#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(const vector<int>& arr, int mid, int m, int k) {
	int n = arr.size();
	int days = 0, madeBouq = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= mid)
			days++;
		else {
			madeBouq += days / k;
			days = 0;
		}
	}
	madeBouq += days / k;
	return madeBouq >= m;
}
int minDays(vector<int>& arr, int m, int k) {
	if (arr.size() < m * k)
		return -1;
	
    int maxEle = *max_element(arr.begin(), arr.end());
	int minEle = *min_element(arr.begin(), arr.end());
	int low = minEle;
	int high = maxEle;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(arr, mid, m, k))
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low > maxEle ? -1 : low;
}
int32_t main() {
	fast

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << minDays(arr, m, k);
	cin.get();
}