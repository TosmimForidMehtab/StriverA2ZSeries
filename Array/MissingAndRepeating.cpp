#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0 and arr[i] <= n) {
			int idx = arr[i] - 1;
			if (arr[i] != arr[idx]) {
				swap(arr[i], arr[idx]);
				i--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] != i + 1) {
			return {i + 1, arr[i]};
		}
	}
	return {n + 1, n};

}
// ================= BEST ====================
pair<int, int> missingAndRepeatingBest(vector<int> &arr, int n)
{
	int m, r;

	// traversing the array
	for (int i = 0; i < n; i += 1)
	{
		if ( arr[abs(arr[i]) - 1] > 0 )
		{
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		}
		// if arr[i] is already negative, it is the repeating number
		else
		{
			r = abs(arr[i]);
		}
	}
	for (int i = 0; i < n; i += 1)
	{
		// the index at which the element is positive is the missing number
		if ( arr[i] > 0 )
		{
			m = i + 1;
			break;
		}
	}
	pair<int, int>ans;
	ans.first = m;
	ans.second = r;
	return ans;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}