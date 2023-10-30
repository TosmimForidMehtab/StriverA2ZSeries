#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool find132pattern1(vector<int>& nums) {
	int n = nums.size();
	stack<int> st;
	int s3 = INT_MIN; // s1 s3 s2
	for (int i = n - 1; i >= 0; i--) {
		if (nums[i] < s3)
			return true;
		while (!st.empty() and st.top() < nums[i]) {
			s3 = st.top();
			st.pop();
		}
		st.push(nums[i]);
	}
	return false;
}
bool find132Pattern2(vector<int>& arr) {
	int n = arr.size();
	stack<pair<int, int>> st; // Maintaining a monotonic decreasing stack
	int currMin = arr[0];
	for (int i = 1; i < n; i++) {
		while (!st.empty() and arr[i] >= st.top().first)
			st.pop();

		if (!st.empty() and arr[i] > st.top().second)
			return true;

		st.push({arr[i], currMin});
		currMin = min(currMin, arr[i]);
	}
	return false;

}
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << find132Pattern2(arr);
	cin.get();
}