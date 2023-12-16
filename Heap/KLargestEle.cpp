#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================

// ================= BEST ====================
vector<int> kLargest(int arr[], int n, int k) {
	// Write your code here
	vector<int> ans;
	priority_queue <int, vector<int>, greater<int>> minHeap;
	int i = 0;
	while (i < n) {
		if (minHeap.size() == k && minHeap.top() < arr[i]) minHeap.pop();
		if (minHeap.size() < k)
			minHeap.push(arr[i]);
		i++;
	}
	while (!minHeap.empty()) {
		ans.push_back(minHeap.top());
		minHeap.pop();
	}
	return ans;
}
int32_t main() {
	fast

	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<int> ans = kLargest(arr, n, k);
	for (int &ele : ans) cout << ele << " ";
	cin.get();
}