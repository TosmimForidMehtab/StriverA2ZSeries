#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// find the floor and ceil of x in arr[]
	sort(arr, arr + n);
	int low = 0, high = n - 1;
	int fl = -1, cl = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) {
			fl = arr[mid];
			cl = arr[mid];
			break;
		} else if (arr[mid] < x) {
			fl = arr[mid];
			low = mid + 1;
		} else if (arr[mid] > x) {
			cl = arr[mid];
			high = mid - 1;
		}
	}
	return {fl, cl};
}

int upperBound(vector<int>& v, int x, int n) {
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		long long mid = low + (high - low) / 2;
		if (v[mid] <= x) {
			low = mid + 1;
		} else if (v[mid] > x) {
			ans = mid;
			high = mid - 1;
		}
	}
	return ans;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	pair<int, int> p = getFloorAndCeil(arr, n, k);
	cout << p.first << " " << p.second << endl;
	cin.get();
}