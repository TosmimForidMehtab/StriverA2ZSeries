#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(const vector<int>& arr, int mid, int m) {
	int student = 1, pages = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (pages + arr[i] > mid) {
			student++;
			pages = arr[i];
		} else
			pages += arr[i];
	}
	return student <= m;
}
int findPages(vector<int>& arr, int n, int m) {
	if (m > n)
		return -1;
	int maxEle = *max_element(arr.begin(), arr.end());
	int sumOfPages = 0;
	sumOfPages = accumulate(arr.begin(), arr.end(), sumOfPages);
	int low = maxEle, high = sumOfPages;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(arr, mid, m))
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << findPages(arr, n, m);
	cin.get();
}