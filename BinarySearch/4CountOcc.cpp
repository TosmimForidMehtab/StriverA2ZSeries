#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int low = 0, high = n - 1;
	int ans = 0;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) {
			ans = mid;
			high = mid - 1;
		} else if (arr[mid] < x) {
			low = mid + 1;
		} else if (arr[mid] > x) {
			high = mid - 1;
		}

	}
	return ans;
}
// Most optimised
int countOpt(const vector<int>& nums, int n, int target) {
	// Write Your Code Here
	if (n == 0)
		return 0;
	int l1 = 0, r1 = n - 1;
	int last = 0, first = 0;
	while (l1 <= r1) {
		int mid = l1 + (r1 - l1) / 2;
		if (nums[mid] == target) {
			last = mid;
			l1 = mid + 1;
		} else if (nums[mid] > target) {
			r1 = mid - 1;
		} else {
			l1 = mid + 1;
		}
	}

	int l2 = 0, r2 = n - 1;
	while (l2 <= r2) {
		int mid = l2 + (r2 - l2) / 2;
		if (nums[mid] == target) {
			first = mid;
			r2 = mid - 1;
		} else if (nums[mid] > target) {
			r2 = mid - 1;
		} else {
			l2 = mid + 1;
		}
	}
	// cout << last << " " << first << endl;
	if(last == first) return 0;
	return last - first + 1;
}
int32_t main() {
	fast

	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << countOpt(arr, n, x) << endl;
	cin.get();
}