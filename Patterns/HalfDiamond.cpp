#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main() {
	fast

	int n;
	cin >> n;
	// This code gives all correct op in local machine but not in online portal
	/* for (int i = 0; i < n; i++) {
	    for (int j = 0; j <= i; j++) {
	        cout << "* ";
	    }
	    cout << endl;
	}
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n - i - 1; j++) {
	        cout << "* ";
	    }
	    cout << endl;
	} */

	for (int i = 1; i <= 2 * n - 1; i++) {
		int stars = i;
		if (i > n)
			stars = 2 * n - i;

		for (int j = 1; j <= stars; j++) {
			cout << "* ";
		}
		cout << endl;
	}
	cin.get();
}