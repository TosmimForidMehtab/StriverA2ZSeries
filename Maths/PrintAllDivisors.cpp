#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long sumOfDiv(int n) {
	long long ans = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			// cout << i << " ";
			ans += i;
			if (n / i != i) {
				ans += n / i;
				// cout << n / i << " ";
			}
		}
	}
	return ans;
}

long long sumOfDivisors(int n) {
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		// ans += sumOfDiv(i);
		ans += (n / i) * i;
	}
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << sumOfDivisors(n);
	cin.get();
}