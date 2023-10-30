#include<bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int M = 1e9 + 7;
long long Power(long long a, long long n) {
	a %= M;
	int ans = 1;
	while (n) {
		if (n & 1) {
			ans = (ans * a) % M;
		}
		a = (a * a) % M;
		n = n >> 1;
	}
	return ans % M;
}
long long PowerRec(long long a, long long n) {
	if (n == 0)
		return 1;
	long long half = PowerRec(a, n / 2);
	long long ans = half * half;
	if (n & 1)
		ans *= a;
	return ans;
}
int countGoodNumbers(long long n) {
	long long even = 5, odd = 4;
	if (!(n & 1)) {
		long long x = n / 2;
		return ((PowerRec(even, x) % M) * (PowerRec(odd, x) % M)) % M;
	}
	long long x = n / 2;
	return ((PowerRec(even, x + 1) % M) * (PowerRec(odd, x) % M)) % M;
}
int32_t main() {
	fast

	long long n;
	cin >> n;
	cout << countGoodNumbers(n);
	cin.get();
}