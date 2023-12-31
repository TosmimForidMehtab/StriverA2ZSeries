#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
double median(vector<int>& nums1, vector<int>& nums2) {
	if (nums2.size() < nums1.size())
		return median(nums2, nums1);
	int n1 = nums1.size();
	int n2 = nums2.size();
	int low = 0, high = n1;

	while (low <= high) {
		int cut1 = (low + high) >> 1;
		int cut2 = (n1 + n2 + 1) / 2 - cut1;


		int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

		int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
		int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];


		if (left1 <= right2 && left2 <= right1) {
			if ((n1 + n2) % 2 == 0)
				return (max(left1, left2) + min(right1, right2)) / 2.0;
			else
				return max(left1, left2);
		} else if (left1 > right2) {
			high = cut1 - 1;
		} else {
			low = cut1 + 1;
		}
	}
	return 0.0;
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	vector<int> arr1(n), arr2(m);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	cout << median(arr1, arr2);
	cin.get();
}