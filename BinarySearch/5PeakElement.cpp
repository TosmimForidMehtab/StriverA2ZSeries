#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int findPeakElement(const vector<int>& nums) {
	int n = nums.size();
	int l = 0, r = n - 1;
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		//The condition mid +1 == n is used for the test case when there is only 2 elements
		if (mid + 1 == n or nums[mid] > nums[mid + 1]) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}