#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
bool isPowerOfTwo(int n) {
	if (n <= 0) return false;
	if (n == 1) return true;
	if (n % 2) return false;

	return isPowerOfTwo(n / 2);
}
// ================= BEST ====================
bool isPowerOfTwoBest(int n) {
	if (n <= 0) return false;

	return (n & (n - 1)) == 0;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << isPowerOfTwoBest(n);
	cin.get();
}