#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main() {
	fast

	int n;
	cin >> n;
	int spaces = 2 * (n - 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		for (int j = 1; j <= spaces; j++) {
			cout << "  ";
		}
		for (int j = i; j >= 1; j--) {
			cout << j<<" ";
		}
		cout << endl;
		spaces -= 2;
	}
	cin.get();
}