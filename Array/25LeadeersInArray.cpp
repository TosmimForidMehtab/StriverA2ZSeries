#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> leaders(int arr[], int n) {
	stack<int> st; // Stack is used in order to maintain the order of elements
	vector<int> ans;

	st.push(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] >= st.top()) st.push(arr[i]);
	}

	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<int> ans = leaders(arr, n);
	for (int x : ans) cout << x << " ";
	cin.get();
}