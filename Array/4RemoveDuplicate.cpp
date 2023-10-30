#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Both Leetcode and Gfg accepted
// Approach 1: Using set. Time Complexity: O(nlog(n)). Space Complexity: O(n)
// Approach 2: Using 2 pointer. Time Complexity: O(n). Space Complexity: O(1)
int remove_duplicate(int a[], int n) {

	int i = 0;

	// Find an element which is different than ith element
	for (int j = 1; j < n; j++) {
		// If found, the i+1th element should be the newly found distinct element
		if (a[i] != a[j]) {
			i++;
			a[i] = a[j];
		}
	}
	return i + 1;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << remove_duplicate(arr, n) << endl;
	cin.get();
}