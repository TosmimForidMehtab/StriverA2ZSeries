#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
void immediateSmallerBrute(vector<int>& arr) {
	// brute force
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) arr[i] = arr[i + 1];
		else arr[i] = -1;
	}
	arr[n - 1] = -1;
}
// ================= BETTER ====================

// ================= BEST ====================
void immediateSmallerBest(vector<int>& arr)

{
	// Write your code here.
	int j = 0;
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		j = i + 1;
		if (arr[i] > arr[j]) {
			arr[i] = arr[j];
		}
		else {
			arr[i] = -1;
		}
		if (i == n - 1) {
			arr[i] = -1;
		}
	}
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}