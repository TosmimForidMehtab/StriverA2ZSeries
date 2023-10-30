#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int findOnes(int arr[], int n, int m) {
	// code here
	int j = -1;
	int ans = INT_MIN;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			count++;
		}
		while (count > m) {
			j++;
			if (arr[j] == 0) {
				count--;
			}
		}
		ans = max(ans, i - j);
	}
	return ans;
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << findOnes(arr, n, m) << endl;
	cin.get();
}