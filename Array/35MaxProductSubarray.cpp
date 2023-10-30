#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int maxProductBruteForce(vector<int>& nums) {
	int result = nums[0];
	for (int i = 0; i < nums.size() - 1; i++) {
		int p = nums[i];
		for (int j = i + 1; j < nums.size(); j++) {
			result = max(result, p);
			p *= nums[j];
		}
		result = max(result, p); //manages (n-1)th term
	}
	return result;
}
// Optimised
int maxProduct(vector<int>& arr) {
	int n = arr.size();
	// Find the maximum product from left
	int maxL = arr[0];
	int maxR = arr[0];
	int prod = 1;
	bool zero = false;
	for (int i = 0; i < n; i++) {
		prod *= arr[i];
		if (arr[i] == 0) {
			zero = true;
			prod = 1;
			continue;
		}
		maxL = max(maxL, prod);
	}

	// Find the maximum product from right
	prod = 1;
	for (int i = n - 1; i >= 0; i--) {
		prod *= arr[i];
		if (arr[i] == 0) {
			zero = true;
			prod = 1;
			continue;
		}
		maxR = max(maxR, prod);
	}

	// Maximum of maxL and maxR is answer
	if (zero)
		return max(max(maxL, maxR), (long long)0);
	return max(maxL, maxR);
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxProduct(arr) << endl;
	cin.get();
}