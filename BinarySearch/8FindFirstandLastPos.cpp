#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> searchRange(const vector<int>& nums, int target) {
	int n = nums.size();
	if (n == 0)
		return {-1, -1};
	int l1 = 0, r1 = n - 1;
	int last = -1, first = -1;
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
	return {first, last};
}
int32_t main() {
	fast

	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ans = searchRange(arr, target);
	cout << ans[0] << " " << ans[1] << endl;
	cin.get();
}