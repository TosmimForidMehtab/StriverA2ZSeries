#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int kthElement(vector<int>& arr1, vector<int>& arr2, int n, int m, int k) {
	if (m < n)
		return kthElement(arr2, arr1, m, n, k);
	// !Important corner cases.
	/*
        ! If k < n: low = 0, high = k
	    ! If k > m: low = k-m, high = n
	    ! Eg. for n = 4, m = 6 and k = 3, low = 0, high = 3
	    ! Eg. for n = 4, m = 6 and k = 7, low = 1, high = 4
	*/
	int low = max(0, k - m), high = min(k, n);
	while (low <= high) {
		int cut1 = low + (high - low) / 2;
		int cut2 = k - cut1;

		int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

		int right1 = cut1 == n ? INT_MAX : arr1[cut1];
		int right2 = cut2 == m ? INT_MAX : arr2[cut2];

		if (left1 <= right2 and left2 <= right1) {
			return max(left1, left2);
		} else if (left1 > right2)
			high = cut1 - 1;
		else
			low = cut1 + 1;
	}
	return 1;
}
int32_t main() {
	fast

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr1(n), arr2(m);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	cout << kthElement(arr1, arr2, n, m, k);
	cin.get();
}