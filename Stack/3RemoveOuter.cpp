#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string removeOuterParentheses(string s) {
	stack<char> st;
	string ans = "";
	for (char ch : s) {
		if (ch == '(') {
			if (!st.empty())
				ans.push_back(ch);
			st.push(ch);
		} else {
			st.pop();
			if (!st.empty())
				ans.push_back(ch);
		}
	}
	return ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << removeOuterParentheses(s);
	cin.get();
}