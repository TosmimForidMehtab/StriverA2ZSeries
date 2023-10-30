#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE O(n*q)====================
vector<int> countGreaterBrute(vector<int>&arr, vector<int>&query) {
	vector<int> ans;
	for (auto ele : query) {
		int cnt = 0;
		for (int i = ele + 1; i < arr.size(); i++) {
			if (arr[i] > arr[ele]) cnt++;
		}
		ans.push_back(cnt);
	}
	return ans;
}
// ================= BETTER ====================

// ================= BEST ====================
int32_t main() {
	fast

	int n, q;
	cin >> n >> q;
	vector<int> arr(n), queries(q);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < q; ++i)
	{
		cin >> queries[i];
	}
	vector<int> ans = countGreaterBrute(arr, queries);

	cout << endl;
	cin.get();
}