#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int myAtoi(string s) {
	int n = s.length();
	if (n == 0)
		return 0;

	int index = 0;
	// Ignoring spaces
	while (index < n and s[index] == ' ')
		index++;

	// Checking for +ve or -ve signs
	int sign = 1;
	if (s[index] == '-')
		sign = -1;
	// cout << s << endl;

	if (s[index] == '+' or s[index] == '-')
		index++;


	long long ans = 0;
	while (index < n) {
		// If anything other than a digit or any space occurs, done parsing
		if (s[index] == ' ' or !isdigit(s[index]))
			break;

		ans = ans * 10 + s[index] - '0';

		// -ve Overflow check
		if (sign == -1 and - 1 * ans < INT_MIN)
			return INT_MIN;

		// +ve overflow check
		if (sign == 1 and ans > INT_MAX)
			return INT_MAX;

		index++;
	}
	return (int)sign * ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << myAtoi(s);
	cin.get();
}