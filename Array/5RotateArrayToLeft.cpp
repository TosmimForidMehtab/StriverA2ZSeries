#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		ans[(i + k) % n] = nums[i];
	}
	for (int i = 0; i < n; ++i) {
		nums[i] = ans[i];
	}
}

void rotate2(vector<int>& nums, int k) {
	int n = nums.size();
	k %= n; // Removing segmentation fault that might occur
	reverse(nums.begin(), nums.begin() + (n - k));
	reverse(nums.begin() + (n - k), nums.end());
	reverse(nums.begin(), nums.end());
}

// GFG
void leftRotate(int arr[], int k, int n) {
	// Your code goes here
	k %= n;
	reverse(arr, arr + (k));
	reverse(arr + (k), arr + n);
	reverse(arr, arr + n);
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << endl;
	cin.get();
}