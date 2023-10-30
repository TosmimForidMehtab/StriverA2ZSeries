#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int largest(const vector<int>& arr, int n) {
	int maxEle = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > maxEle)
			maxEle = arr[i];
	}
	return maxEle;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << largest(arr, n) << endl;
	cin.get();
}