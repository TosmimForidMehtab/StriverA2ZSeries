#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void solve(vector<int> &arr, vector<int> & temp, int idx, int sum) {
	if (idx == arr.size()) {
		temp.push_back(sum);
		return;
	}

	sum += arr[idx];
	solve(arr, temp, idx + 1, sum);
	sum -= arr[idx];
	solve(arr, temp, idx + 1, sum);
}
vector<int> subsetSum(vector<int> &num) {
	vector<int> ans;
	solve(num, ans, 0, 0);
	sort(ans.begin(), ans.end());
	return ans;
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
	vector<int> ans = subsetSum(arr);
	for (int &x : ans) cout << x << " ";
	cin.get();
}