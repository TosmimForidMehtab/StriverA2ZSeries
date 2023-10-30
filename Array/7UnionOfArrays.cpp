#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
	//Your code here
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[arr1[i]]++;
	}
	for (int i = 0; i < m; i++) {
		mp[arr2[i]]++;
	}
	vector<int> ans;
	for (auto x : mp) {
		ans.push_back(x.first);
	}
	return ans;
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	int arr1[n], arr2[m];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	vector<int> ans = findUnion(arr1, arr2, n, m);
	for (int x : ans)
		cout << x << " ";
	cin.get();
}