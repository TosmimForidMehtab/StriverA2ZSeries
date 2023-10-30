#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Find the index of the minimum element in the sorted rotated array
int findKRotation(const vector<int>& arr) {
	int n = arr.size();
	int low = 0, high = n - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] > arr[high])
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << findKRotation(arr) << endl;
	cin.get();
}