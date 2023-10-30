#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string is_palindrome(int n) {
	int num = n;
	int rev = 0;
	while (num) {
		int rem = num % 10;
		rev = rev * 10 + rem;
		num /= 10;

	}
	if (rev == n)
		return "Yes";
	return "No";
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << is_palindrome(n);
	cin.get();
}