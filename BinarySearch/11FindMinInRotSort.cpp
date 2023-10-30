#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int search(vector<int>& nums, int l, int r) {
	if (l == r)
		return nums[l];
	int mid = l + (r - l) / 2;
	if (nums[mid] > nums[r])
		return search(nums, mid + 1, r);
	if (nums[mid] < nums[r])
		return search(nums, l, mid);
	return nums[r];
}
int findMinRec(vector<int>& nums) {
	return search(nums, 0, nums.size() - 1);
}
int findMin(const vector<int>& nums) {
	int s = 0, e = nums.size() - 1;
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (nums[mid] > nums[e])
			s = mid + 1;
		else
			e = mid;
	}
	return nums[s];

}
// Find Min
int findMin2(const vector<int>& nums) {
	int ans = INT_MAX, low = 0, high = nums.size() - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		// Left array is sorted. So, the minimum element on the left half is the first element. Check for the right half
		if (nums[low] <= nums[mid]) {
			ans = min(ans, nums[low]);
			low = mid + 1;
		} else {
			ans = min(ans, nums[mid]);
			high = mid - 1;
		}
	}
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << findMin(arr) << endl;
	cin.get();
}