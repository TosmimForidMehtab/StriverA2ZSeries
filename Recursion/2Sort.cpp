#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Can also use merge sort
// Recursively sort a string
void sortString(string& s, int n) {
	if (n == 1)
		return;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] > s[i + 1])
			swap(s[i], s[i + 1]);
	}
	sortString(s, n - 1);
}
int32_t main() {
	fast

	string s;
	getline(cin, s);
	int n = s.length();
	sortString(s, n);
	for (char& ch : s)
		cout << ch << " ";
	cin.get();
}