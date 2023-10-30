#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Find the second largest element in an array
int print2largest(int arr[], int n) {
	// code here
	int largest = INT_MIN, secLargest = INT_MIN;
	for (int i = 0; i < n; i++) {
		largest = max(arr[i], largest);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > secLargest and arr[i] != largest) {
			secLargest = arr[i];
		}
	}
	return secLargest != INT_MIN ? secLargest : -1;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << print2largest(arr, n) << endl;
	cin.get();
}