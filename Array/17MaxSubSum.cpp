#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long maxSubarraySum(int arr[], int n) {
	long long maxSum = INT_MIN;
	long long currSum = 0;
	for (int i = 0; i < n; i++) {
		currSum += arr[i];
		if (currSum > maxSum) {
			maxSum = currSum;
		}
		if (currSum < 0) {
			currSum = 0;
		}
	}
	return maxSum;
}
int32_t main() {
	fast

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxSubarraySum(a, n) << endl;
	cin.get();
}