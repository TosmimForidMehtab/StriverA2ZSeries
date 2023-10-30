#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(vector<int>& arr, int mid, int th) {
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		ans += (int)ceil(arr[i] * 1.0 / mid);
	}
	return ans <= th;
}
int minDiv(vector<int>& arr, int th) {
	int n = arr.size();
	if (th == n)
		return n;
	int low = 1;
	int high = *max_element(arr.begin(), arr.end());
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (isPossible(arr, mid, th))
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}
int32_t main() {
	fast

	int n, th;
	cin >> n >> th;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << minDiv(arr, th);
	cin.get();
}