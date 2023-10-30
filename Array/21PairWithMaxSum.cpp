#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long pairWithMaxSum(long long arr[], long long N) {
	int maxSum = 0, currSum = 0;
	for (int i = 0; i < N - 1; i++) {
		currSum = arr[i] + arr[i + 1];
		// cout << currSum << endl;
		if (currSum > maxSum) {
			maxSum = currSum;
		}
	}
	return maxSum;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << pairWithMaxSum(arr, n) << endl;
	cout << endl;
	cin.get();
}