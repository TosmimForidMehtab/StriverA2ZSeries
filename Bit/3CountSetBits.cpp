#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// N & (N-1) is called the Brian Kernighan’s Algorithm
int countSetBits(int N) {
	int ans = 0;
	while (N) {
		N &= (N - 1);
		ans++;
	}
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << countSetBits(n);
	cin.get();
}