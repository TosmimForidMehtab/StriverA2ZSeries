#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main() {
	fast

	int n;
	cin >> n;
	int k;
	for (int i = 1; i <= n; i++) {
		if (i % 2)
			k = 1;
		else
			k = 0;
		for (int j = 1; j <= i; j++) {
			cout << k << " ";
			k = k ^ 1;
		}
		cout << endl;
	}
	cin.get();
}