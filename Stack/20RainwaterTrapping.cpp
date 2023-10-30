#include<bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

// ================= BRUTE ====================
int trap(vector<int>& height) {
	int n = height.size();
	int maxWater = 0;
	for (int i = 0; i < n; ++i)
	{
		int maxLeft = 0, maxRight = 0;
		for (int j = i; j < n; j++) {
			maxRight = max(maxRight, height[j]);
		}

		for (int j = i; j >= 0; j--) {
			maxLeft = max(maxLeft, height[j]);
		}

		maxWater += min(maxLeft, maxRight) - height[i];
	}
	return maxWater;
}
// ================= BETTER ====================

int trapBett(vector<int> &height) {
	int n = height.size();
	vector<int> ngl(n), ngr(n);
	ngl[0] = height[0];
	for (int i = 1; i < n; i++) {
		ngl[i] = max(ngl[i - 1], height[i]);
	}
	ngr[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		ngr[i] = max(ngr[i + 1], height[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += min(ngl[i], ngr[i]) - height[i];
	}
	return ans;
}
// ================= BEST ====================
int trapBest(vector<int> &height) {
	int n = height.size();
	stack<int> st;
	int maxArea = 0;
	for (int i = 0; i < n; ++i)
	{
		while (!st.empty() and height[st.top()] < height[i]) {
			// Calculate area
			int prevIndex = st.top();
			st.pop();

			if (!st.empty()) {
				int h = min(height[i], height[st.top()]) - height[prevIndex];
				maxArea += h * (i - 1 - st.top());
			}
		}
		st.push(i);
	}
	return maxArea;
}
// Intersting Approach
long long getTrappedWater(long long* arr, int n) {
	long long res = 0;
	int left = 0;
	int right = n - 1;
	int maxLeft = 0, maxRight = 0;
	while (left <= right) {
		if (arr[left] <= arr[right]) {
			if (arr[left] >= maxLeft) {
				maxLeft = arr[left];
			}
			else {
				res += maxLeft - arr[left];
			}
			left++;
		}
		else {
			if (arr[right] >= maxRight) {
				maxRight = arr[right];
			}
			else {
				res += maxRight - arr[right];
			}
			right--;
		}
	}
	return res;

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
	cout << trapBest(arr);
	cin.get();
}