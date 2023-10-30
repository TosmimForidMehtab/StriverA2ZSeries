#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void sort012(int a[], int n) {
	int low  = 0, mid = 0, high = n - 1;
	while (mid <= high) {
		if (a[mid] == 0) {
			swap(a[low], a[mid]);
			low++;
			mid++;
		} else if (a[mid] == 1) {
			mid++;
		} else {
			swap(a[mid], a[high]);
			high--;
		}
	}
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort012(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cin.get();
}