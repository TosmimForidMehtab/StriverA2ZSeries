#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int i, j;
	for (i = n - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) break;
	}

	if (i < 0) reverse(nums.begin(), nums.end());

	else {

		for (j = n - 1; j >= i; j--) {
			if (nums[j] > nums[i]) {
				swap(nums[j], nums[i]);
				break;
			}
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	nextPermutation(arr);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cin.get();
}