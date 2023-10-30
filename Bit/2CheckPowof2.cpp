#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// O(logn)
bool isPowerOfTwo(int n) {
	if (n == 0) return false;
	while (n % 2 == 0) n /= 2;
	return n == 1;
}

// Bit O(1)
// The number which are power of 2 has one set bit only
bool isPowerOfTwoBit(int n) {
	if (n <= 0) return false;
	// Checking if removing the rightmost set bit makes the number as zero, that means the unset bit was the only set bit
	return ((n & (n - 1)) == 0);
}
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	int n;
	cin >> n;
	cout << isPowerOfTwo(n);
	cin.get();
}