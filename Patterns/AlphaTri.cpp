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
		for (char ch = ('A' + n - 1); ch >= ('A' + n - 1) - i; ch--) {
			cout << ch << " ";
		}
		cout << endl;
	}
	cin.get();
}