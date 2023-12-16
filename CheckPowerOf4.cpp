#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
bool isPowerOfFour(int n) {
	if (n <= 0) return false;
	if (n == 1) return true;
	if (n % 4) return false;
	return isPowerOfFour(n / 4);
}
// ================= BEST ====================
bool isPowerOfFourBest(int n) {
// logbase2(2^2y) =2y
	if (n <= 0) return false;
	double lg2 = log2(n);
	if (lg2 != (int)lg2) return false;
	return (int)lg2 % 2 == 0;
}
bool isPowerOfFourBest2(int n) {
	if (!n) return false;
	const unsigned z = __builtin_ctz(n);
	return (z & 1) == 0 && n == 1 << z;
}
bool isPowerOfFourBest3(int n) {
	return n > 0 && !(n & (n - 1)) && (n & 0x55555555);
}
bool isPowerOfFourBest4(int n) {
	return n > 0 && !(n & (n - 1)) && !(n & 0x2aaaaaaa);
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}