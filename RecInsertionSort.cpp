#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void insertionSort(int arr[], int n, int i) {
	if (i == n)
		return;

	int j = i;
	while (j and arr[j - 1] > arr[j]) {
		int temp = arr[j - 1];
		arr[j - 1] = arr[j];
		arr[j] = temp;
		j--;
	}

	insertionSort(arr, n, i + 1);
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	insertionSort(arr, n, 0);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cin.get();
}