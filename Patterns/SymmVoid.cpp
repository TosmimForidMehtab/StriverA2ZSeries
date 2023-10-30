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
		for (int j  = 0; j < n - i; j++)
			cout << "*";

		for (int j = 1; j <= 2 * i; j++)
			cout << " ";

		for (int j  = 0; j < n - i; j++)
			cout << "*";
		cout << endl;

	}

	for (int i = 1; i <= n; i++) {
		for (int j  = 0; j < i; j++)
			cout << "*";

		for (int j = 1; j <= 2 * (n - i); j++)
			cout << " ";

		for (int j  = 0; j < i; j++)
			cout << "*";
		cout << endl;

	}
	cin.get();
}