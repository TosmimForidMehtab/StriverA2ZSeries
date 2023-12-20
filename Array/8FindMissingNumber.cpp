#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int missingNumber(const vector<int>& nums) {
	int n = nums.size();
	int sum = (n * (n + 1)) / 2;
	for (int i = 0; i < n; i++) {
		sum -= nums[i];
	}
	return sum;
}

int missingNumber2(vector<int>& nums) {
	int n = nums.size();
	int mp[n + 1] = {0};
	for (int i = 0; i < n; i++) {
		mp[nums[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (mp[i] == 0) {
			return i;
		}
	}
	return -1;
}

// TODO: Not Clear
int missingNumber3(vector<int>& nums) {
	int n = nums.size();
	int xor1 = 0, xor2 = 0;
	for (int i = 0; i < n - 1; i++) {
		xor2 = xor2 ^ nums[i]; // xor of array elements
		xor1 = xor1 ^ (i + 1); // xor upto [1 ... n-1]
	}
	xor1 = xor1 ^ n; // xor upto [1 ... n]

	return (xor1 ^ xor2);
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << missingNumber2(arr) << endl;
	cin.get();
}