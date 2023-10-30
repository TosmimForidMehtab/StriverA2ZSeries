#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int xAndY(int x, int y, vector<int> &a)
{
	// Write your code here
	int smallest = INT_MAX;
	int n = a.size();
	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= x and a[i] <= y) {
			if (a[i] < smallest) smallest = a[i];
		}
	}
	return smallest == INT_MAX ? -1 : smallest;
}
int32_t main() {
	fast

	int n, x, y;
	cin >> n >> x >> y;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << xAndY(x, y, arr);
	cin.get();
}