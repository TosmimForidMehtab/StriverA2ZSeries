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
		for (int j = 0; j < n; j++) {
			if (i == 0 or j == 0 or i == n - 1 or j == n - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	cin.get();
}