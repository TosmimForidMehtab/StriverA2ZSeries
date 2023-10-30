#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> rearrangeArrayLC(vector<int>& nums) {
	int n = nums.size();
	vector<int> pos, neg;
	for (int x : nums) {
		if (x > 0) pos.push_back(x);
		else neg.push_back(x);
	}

	for (int i = 0; i < n / 2; ++i)
	{
		nums[2 * i] = pos[i];
		nums[2 * i + 1] = neg[i];
	}
	return nums;
}

vector<int> rearrangeArrayLC2(vector<int>& nums) {
	int n = nums.size();
	vector<int> ans(n, 0);

	int posI = 0, negI = 1;
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] < 0) {
			ans[negI] = nums[i];
			negI += 2;
		}
		else {
			ans[posI] = nums[i];
			posI += 2;
		}
	}
	return ans;
}
// TODO: Shows segmentation Fault
void rearrangeGFG(int arr[], int n) {
	int ans[n] = {0};
	int posI = 0, negI = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			ans[negI] = arr[i];
			negI += 2;
		}
		else {
			ans[posI] = arr[i];
			posI += 2;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
}
int32_t main() {
	fast

	int n;
	cin >> n;
	// vector<int> arr(n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	// vector<int> ans = rearrangeArray(arr);
	// for (int x : ans) cout << x << " ";

	// rearrangeGFG(arr, n);
	cin.get();
}