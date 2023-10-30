#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// No duplicates
int missingNumber(vector<int>& arr, int n) {
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int element = arr[i];
		if (element > 0 and element <= n) {
			int position = element - 1;


			if (element != arr[position]) {
				swap(arr[i], arr[position]);
				i--;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] != i + 1) {
			ans = i + 1;
		}
	}

	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << missingNumber(arr, n);
	cin.get();
}