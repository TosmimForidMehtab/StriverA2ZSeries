#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// O(n) complexity
int kthPositive(const vector<int>& arr, int k) {
	int n = arr.size();
	int number = 1;
	int i = 0;
	while (i < n and k) {
		if (arr[i] == number)
			i++;
		else
			k--;
		number++;
	}

	// If no missing number found in the array
	while (k--)
		number++;
	return number - 1;
}
int kthPositiveOpt(const vector<int>& arr, int k) {
	int n = arr.size();
	int low = 0, high = n - 1;
	// Number of missiing numbers for ith index = arr[j]-j+1
	while (low <= high) {
		int mid = low + (high - low) / 2;
		int noOfNum = arr[mid] - (mid + 1);
		if (noOfNum < k)
			low = mid + 1;
		else
			high = mid - 1;
	}
	// Ans = l+k
	return low + k;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << kthPositiveOpt(arr, k);
	cin.get();
}