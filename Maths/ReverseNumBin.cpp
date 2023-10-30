#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
long long reversedBits(long long X) {
	long long ans = 0;
	int d = 0;
	while (X) {
		ans += (X % 2) << (31 - d);
		X >>= 1;
		d++;
	}
	return ans;
}

long long reversedBits2(long long X) {
	long long res = 0;
	for (int i = 0; i < 32; i++) {
		res <<= 1;
		if (X & 1)
			res++;
		X >>= 1;
	}
	return res;
}

int32_t main() {
	fast

	int n;
	cin >> n;
	cout << reversedBits2(n);
	cin.get();
}