#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void bubbleSort(int arr[], int n, int i) {
	if (i == n)
		return;

	for (int j = 0; j < n - i - 1; j++) {
		if (arr[j] > arr[j + 1]) {
			swap(arr[j], arr[j + 1]);
		}
	}
	bubbleSort(arr, n, i + 1);
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bubbleSort(arr, n, 0);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cin.get();
}