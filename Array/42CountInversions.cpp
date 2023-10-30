#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int merge(vector<int>& a, int l, int mid, int r) {
	int cnt = 0;
	vector<int> temp;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j])
			temp.push_back(a[i++]);
		else {
			temp.push_back(a[j++]);
			cnt += mid - i + 1;
		}
	}
	while (i <= mid)
		temp.push_back(a[i++]);
	while (j <= r)
		temp.push_back(a[j++]);
	for (int i = l; i <= r; i++)
		a[i] = temp[i - l];
	return cnt;
}
int mergeSort(vector<int>& a, int l, int r) {
	int cnt = 0;
	if (l >= r)
		return cnt;

	int mid = (l + r) / 2;
	cnt += mergeSort(a, l, mid);
	cnt += mergeSort(a, mid + 1, r);
	cnt += merge(a, l, mid, r);
	return cnt;
}
int numberOfInversions(vector<int>& a, int n) {
	return mergeSort(a, 0, n - 1);
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << numberOfInversions(arr, n);
	cin.get();
}