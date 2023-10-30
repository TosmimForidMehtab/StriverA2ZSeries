#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// O(n)
int singleNonDuplicate(vector<int>& nums) {
	int n = nums.size();
	int xorSum = 0;
	for (int i = 0; i < n; i++) {
		xorSum ^= nums[i];
	}
	return xorSum;
}
// O(logn)
int singleNonDuplicateOpt(const vector<int>& arr) {
	int n = arr.size();

	if (n == 1)
		return arr[0];
	if (arr[0] != arr[1])
		return arr[0];
	if (arr[n - 1] != arr[n - 2])
		return arr[n - 1];

	int low = 1, high = n - 2;
	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
			return arr[mid];
		}

		// In left half
		// TODO How does this work???
		if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
		    || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
			// Move to right
			low = mid + 1;
		}
		// In right half
		else {
			// Move to left
			high = mid - 1;
		}
	}

	return -1;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << singleNonDuplicateOpt(arr) << endl;
	cin.get();
}