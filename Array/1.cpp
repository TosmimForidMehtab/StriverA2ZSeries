#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long contributions(int n, vector<int> &a) {
	// Write your code here.
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; j++) {
			if (a[i] % 3 == a[j] % 3) {
				sum += a[i] ^ a[j];
			}
		}
	}
	return sum;
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
	cout << contributions(n, arr);
	cin.get();
}