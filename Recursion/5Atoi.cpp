#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
//* Recursive
int solve(string s, int sign, int index, long long ans) {
	if (sign * ans > INT_MAX)
		return INT_MAX;
	if (sign * ans < INT_MIN)
		return INT_MIN;
	if (s[index] == ' ' or !isdigit(s[index]))
		return ans * sign;
	return solve(s, sign, index + 1, ans * 10 + s[index] - '0');
}
int myAtoi(string s) {
	int n = s.length();
	if (n == 0)
		return 0;
	int index = 0;
	while (index < n and s[index] == ' ')
		index++;

	int sign = 1;
	if (s[index] == '-')
		sign = -1;

	if (s[index] == '+' or s[index] == '-')
		index++;
	return solve(s, sign, index, 0);
}
//* Iterative
int myAtoiIter(string s) {
	int n = s.length();
	if (n == 0)
		return 0;
	int index = 0;
	while (index < n and s[index] == ' ')
		index++;

	int sign = 1;
	if (s[index] == '-')
		sign = -1;

	if (s[index] == '+' or s[index] == '-')
		index++;

	long long ans = 0;
	while (index < n) {
		if (s[index] == ' ' or !isdigit(s[index]))
			break;
		ans = ans * 10 + s[index] - '0';
		if (sign == -1 and - 1 * ans < INT_MIN)
			return INT_MIN;
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