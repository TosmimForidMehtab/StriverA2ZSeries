#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
//Brute Force
long long power(int b, int exp) {
	long long  ans = 1;
	long long base = b;
	while (exp > 0) {
		if (exp % 2) {
			exp--;
			ans = ans * base;
		} else {
			exp /= 2;
			base = base * base;
		}
	}
	return ans;
}

int NthRoot1(int n, int m) {
	//Use linear search on the answer space:
	for (int i = 1; i <= m; i++) {
		long long val = power(i, n);
		if (val == m * 1ll)
			return i;
		else if (val > m * 1ll)
			break;
	}
	return -1;
}
// Find the nth root of a m using binary search
int NthRoot(int n, int m) {
	int low = 1, high = m;
	while (low <= high) {
		int mid = (low + high) / 2;
		long long midVal = power(mid, n);
		if (midVal == n) {
			return mid;
		}
		if (midVal < n) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}
// TODO: 1 test case is failing
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	cout << NthRoot(n, m) << endl;
	cin.get();
}