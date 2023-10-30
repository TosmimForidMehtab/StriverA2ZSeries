#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int evenlyDivides(int N) {
	int count = 0;
	int num = N;
	while (num) {
		int rem = num % 10;
		num /= 10;
		if (rem and N % rem == 0)
			count++;
	}
	return count;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << evenlyDivides(n) << endl;
	cin.get();
}