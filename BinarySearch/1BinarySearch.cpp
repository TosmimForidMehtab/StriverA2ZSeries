#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int search(const vector<int>& nums, int target) {
	int low = 0, high = nums.size() - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}
int32_t main() {
	fast

	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << search(arr, target) << endl;
	cin.get();
}