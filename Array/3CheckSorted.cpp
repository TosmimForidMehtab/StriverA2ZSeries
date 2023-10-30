#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// GFG version
bool arraySortedOrNot(int arr[], int n) {
	// code here
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

// Leetcode version
// Check if array is sorted and rotated
bool check(const vector<int>& nums) {
	// Count the number of times the array is broken. If the number of times the array is broken is less than or equal to 1, then the array is sorted and rotated.
	int count = 0, n = nums.size();
	for (int i = 1; i < n; i++) {
		if (nums[i] < nums[i - 1]) {
			count++;
		}
	}
	if (count > 1)
		return false;
	if (nums[0] < nums[n - 1] and count != 0)
		return false;
	return true;
}
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << arraySortedOrNot(arr, n) << endl;
	cout << check(nums) << endl;
	cin.get();
}