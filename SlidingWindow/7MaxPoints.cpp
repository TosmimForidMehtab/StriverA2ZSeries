#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
int maxScore(vector<int>& cardPoints, int k) {
	int n = cardPoints.size();
	int sum = 0, maxSum = 0;
	for (int i = 0; i < k; ++i) sum += cardPoints[i];
	maxSum = sum;
	for (int i = k - 1; i >= 0; i--) {
		sum -= cardPoints[i];
		sum += cardPoints[n - k + i];
		maxSum = max(sum , maxSum);
	}
	return maxSum;
}
// ================= BEST ====================

int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << maxScore(arr, k);
	cin.get();
}