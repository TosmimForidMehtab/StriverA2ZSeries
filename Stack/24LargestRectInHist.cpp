#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
int largestRectangleAreaBrute(vector<int>& heights) {
	int n = heights.size();
	long long maxArea = 0;
	for (int i = 0; i < n; ++i)
	{
		long long currSum = heights[i];
		for (int j = i + 1; j < n; j++) {
			if (heights[j] > heights[i]) {
				currSum += heights[i];
			}
			else break;
		}
		if (currSum > maxArea) maxArea = currSum;
	}
	return (int)maxArea;
}
// ================= BETTER ====================
stack<int> st;
vector<int> NSL(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		while (!st.empty() and arr[st.top()] >= arr[i]) st.pop();
		if (!st.empty()) ans[i] = st.top() + 1;
		else ans[i] = 0;
		st.push(i);
	}
	return ans;
}
vector<int> NSR(vector<int> &arr) {
	int n = arr.size();
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and arr[st.top()] >= arr[i]) st.pop();
		if (!st.empty()) ans[i] = st.top() - 1;
		else ans[i] = n - 1;
		st.push(i);
	}
	return ans;
}
int largestRectangleAreaBett(vector<int> &heights) {
	int n = heights.size();
	if (n == 0) return 0;
	if (n == 1) return heights[0];
	vector<int> nsr = NSR(heights);
	while (!st.empty()) st.pop();
	vector<int> nsl = NSL(heights);
	long long maxArea = 0;
	for (int i = 0; i < n; ++i)
	{
		int width = nsr[i] - nsl[i] + 1;
		int height = heights[i];
		long long area = height * width;
		if (area > maxArea) maxArea = area;
	}
	return (int)maxArea;
}
// ================= BEST ====================
int largestRectangleAreaBest(vector<int>& heights) {
	stack<int> st;
	int maxArea = 0;
	for (int i = 0 ; i <= heights.size(); i++) {
		while (!st.empty() && (i == heights.size() or heights[st.top()] >= heights[i])) {
			int height = heights[st.top()];
			st.pop();
			int width ;
			if (st.empty()) width = i;
			else width = i - st.top() - 1;
			maxArea = max(maxArea, width * height);
		}
		st.push(i);
	}
	return maxArea;

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
	cout << largestRectangleAreaBett(arr);
	cin.get();
}