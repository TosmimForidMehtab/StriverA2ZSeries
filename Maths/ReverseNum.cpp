#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int reverse(int x) {
	int ans = 0;
	while (x) {
		ans = ans * 10 + x % 10;
		x /= 10;
	}

	return ans > INT_MAX or ans < INT_MIN ? 0 : ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << reverse(n);
	cin.get();
}