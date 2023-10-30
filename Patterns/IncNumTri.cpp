#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main() {
	fast

	int n;
	cin >> n;
	int k = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << k++ << " ";
		}
		cout << endl;
	}
	cin.get();
}