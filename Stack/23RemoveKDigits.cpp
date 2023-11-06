#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
string removeKdigitsBrute(string num, int k) {
	int n = num.length();
	string smallest = num;

	for (int i = 0; i < k; i++) {
		int j = 0;
		while (j < smallest.length() - 1 && smallest[j] <= smallest[j + 1]) {
			j++;
		}
		smallest.erase(j, 1);
	}

	// Remove leading zeros
	int start = 0;
	while (start < smallest.length() - 1 && smallest[start] == '0') {
		start++;
	}

	return smallest.substr(start);
}
// ================= BETTER ====================

// ================= BEST ====================
string removeKdigitsBett(string num, int k) {
	int n = num.size();
	if (n <= k) return "0";
	if (k == 0) return num;
	stack<char> st;
	st.push(num[0]);
	for (int i = 1; i < n; ++i)
	{
		while (k and !st.empty() and st.top() > num[i]) {
			st.pop();
			k--;
		}

		st.push(num[i]);

		while (st.size() == 1 and num[i] == '0') st.pop();
	}

	while (!st.empty() and k) {
		k--;
		st.pop();
	}

	string ans = "";
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() == 0) return "0";
	return ans;
}
int32_t main() {
	fast
	int k;
	cin >> k;
	string s;
	cin >> s;
	cout << removeKdigitsBrute(s, k);
	cin.get();
}