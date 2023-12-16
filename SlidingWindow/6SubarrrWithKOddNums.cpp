#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
int numberOfSubarrays(vector<int>& nums, int k) {

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
	cout << numberOfSubarrays(arr, k);
	cin.get();
}