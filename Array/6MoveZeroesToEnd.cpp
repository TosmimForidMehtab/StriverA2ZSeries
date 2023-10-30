#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void moveZeroes(vector<int>& nums) {
	int n = nums.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] != 0) {
			nums[j++] = nums[i];
		}
	}
	while (j < n) {
		nums[j++] = 0;
	}
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	moveZeroes(arr);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cin.get();
}