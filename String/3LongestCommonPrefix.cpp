#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
	// Compare first string to every string and find the minimum index upto which the strings are same.
	int n = strs.size();
	if (n == 1)
		return strs[0];
	int minIndex = INT_MAX;
	string temp = strs[0];
	for (int i = 1; i < n; i++) {
		int index = 0, tempIndex = 0, strIndex = 0;
		while (tempIndex < temp.size() and strIndex < strs[i].size()) {
			if (temp[tempIndex++] == strs[i][strIndex++])
				index++;
			else
				break;
		}
		minIndex = min(minIndex, index);
	}
	return minIndex == INT_MAX ? "" : temp.substr(0, minIndex);
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	cout << longestCommonPrefix(str);
	cin.get();
}