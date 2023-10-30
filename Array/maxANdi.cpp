#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long maxiAnd(int n, vector<int> &a) {
	// Write your code here
	long long maxI = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = a[i] & -a[i]; j > 0; j = j & (j - 1)) {
			a[i] ^= j;
			maxI = max(maxI, a[i]);
		}
		int ans = 1;
		for (int k =  0; k < n; k++) {
			ans = ans & a[k];
		}
		maxI = max(maxI, ans);
		a[i] ^= j;
	}
	return maxI;
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
	cout << maxiAnd(n, arr);
	cin.get();
}
// 3 5 4 1 ^ 5 2 ^ 5 3 ^ 5 4 ^ 5 5 ^5