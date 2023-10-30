#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int partition(int arr[], int l, int r) {
	int pivot = arr[l];
	int i = l, j = r;

	while (i < j) {
		while (i < r and arr[i] <= pivot)
			i++;
		while (j > l and arr[j] > pivot)
			j--;
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}
void qs(int arr[], int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);
		qs(arr, l, p - 1);
		qs(arr, p + 1, r);
	}
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	qs(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cin.get();
}