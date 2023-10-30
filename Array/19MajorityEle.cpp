#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int majorityElement(int a[], int size) {
	unordered_map<int, int> mp;
	for (int i = 0; i < size; i++) {
		mp[a[i]]++;
	}
	for (auto it : mp) {
		if (it.second > size / 2) {
			return it.first;
		}
	}
	return -1;
}
// TODO: Using Boyer Moore Majority Vote Algorithm
int32_t main() {
	fast

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << majorityElement(a, n) << endl;
	cin.get();
}