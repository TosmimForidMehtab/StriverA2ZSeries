#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string largestOddNumber(string num) {
	//* Find the largest odd number index
	int n = num.size();
	int maxNum = INT_MIN, index = -1;
	for (int i = 0; i < n; i++) {

		int x = num[i] - '0';
		if ((x & 1) and x > maxNum) {
			index = i;
		}
	}
	return index == -1 ? "" : num.substr(0, index+1);
}
int32_t main() {
	fast

	string num;
	cin >> num;
	cout << largestOddNumber(num);
	cin.get();
}