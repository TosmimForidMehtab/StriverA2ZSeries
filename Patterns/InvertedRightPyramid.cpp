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
		for (int j = n - i; j > 0; j--) {
			cout << "* ";
		}
		cout << endl;
	}
	cout << endl;
	cin.get();
}