#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int searchInsert(const vector<int>& nums, int target) {
	int n = nums.size();
	int l = 0, r = n - 1;
	int mid = 0;
	while (l <= r) {
		mid = l + (r - l) / 2;
		// If target is not present in the array
		if (l == r) {
			if (target > nums[r])
				return r + 1;
			else
				return r;
		}
		// If target is present in the array
		if (nums[mid] == target)
			return mid;
		if (nums[mid] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return mid; // Have to return mid because if target is not present in the array, then it will return the last element
}
int32_t main() {
	fast

	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << searchInsert(arr, target) << endl;
	cin.get();
}