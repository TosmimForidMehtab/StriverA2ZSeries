#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main() {
	fast

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		// Print spaces
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		// Print stars
		for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
			cout << "*";
		}
		// Print spaces
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << endl;
	}
	cin.get();
}