#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void frequencyCount(vector<int>& arr, int N, int P) {
	unordered_map<int, int> mp;
	for (int i = 0; i <= N; i++) {
		mp[arr[i]]++;
	}

	arr.clear();
	for (int i = 1; i <= N; i++) {
		// cout << mp[i] << " ";
		arr.push_back(mp[i]);
	}
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int p;
	cin >> p;
	frequencyCount(arr, n, p);
	cin.get();
}