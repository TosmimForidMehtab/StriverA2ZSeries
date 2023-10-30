#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main() {
	fast

	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			int top = i;
			int bottom = j;
			int right = (2 * n - 2) - j;
			int left = (2 * n - 2) - i;
			cout << (n - min({top, bottom, left, right})) << " ";
		}
		cout << endl;
	}
	cin.get();
}