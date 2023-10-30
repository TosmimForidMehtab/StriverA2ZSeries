#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
double solve(double x, int n) {
	if (n == 0)
		return 1;
	long double half = solve(x, n / 2);
	long double ans = half * half;
	if (n & 1)
		ans *= x;
	return ans;
}
double myPow(double x, int n) {
	long double ans = solve(x, n);
	if (n < 0)
		return 1 / ans;
	return ans;
}
//* Iterative
double myPowIter(double x, int n) {
	double ans = 1.0;
	long long nn = n;
	if (nn < 0)
		nn *= -1;
	while (nn) {
		if (nn % 2) {
			ans *= x;
			nn -= 1;
		} else {
			x *= x;
			nn /= 2;
		}
	}
	if (n < 0) {
		ans = (double)1.0 / (double)ans;
	}
	return ans;
}
int32_t main() {
	fast

	double x;
	int n;
	cin >> x >> n;
	cout << fixed << setprecision(5) << myPow(x, n);
	cin.get();
}