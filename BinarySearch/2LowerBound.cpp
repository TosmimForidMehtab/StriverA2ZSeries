#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int findFloor(vector<long long> v, long long n, long long x) {

	// Your code here
	sort(v.begin(), v.end());
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		long long mid = low + (high - low) / 2;
		if (v[mid] <= x) {
			ans = mid;
			low = mid + 1;
		} else if (v[mid] > x) {
			high = mid - 1;
		}
	}
	return ans;
}

// Lower bound Coding Ninjas
int lowerBound(vector<int> v, int n, int x) {
	// Write your code here
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		long long mid = low + (high - low) / 2;
		if (v[mid] < x) {
			low = mid + 1;
		} else if (v[mid] >= x) {
			ans = mid;
			high = mid - 1;
		}
	}
	return ans == -1 ? n : ans;
}

int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << findFloor(v, n, k) << endl;
	cin.get();
}