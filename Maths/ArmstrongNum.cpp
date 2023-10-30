#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string armstrongNumber(int n) {
	int original = n;
	int temp  = n;
	int count  = 0;
	while (temp) {
		count++;
		temp /= 10;
	}
	int sum = 0;
	while (n) {
		int rem = n % 10;
		sum += pow(rem, count);
		n /= 10;
	}

	if (original == sum)
		return "Yes";
	return "No";
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << armstrongNumber(n);
	cin.get();
}