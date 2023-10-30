#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string prefixToPostfix(string s) {
	int n = s.length();
	stack<string>st;
	string result = "";
	for (int i = n - 1; i >= 0; i--)
	{
		char c = s[i];
		if ((c == '+' || c == '-' || c == '*' || c == '/') && !st.empty()) {
			string s1 = st.top(); st.pop();
			string s2 = st.top(); st.pop();
			result = s1 + s2 + c;
			st.push(result);
		}
		else {
			string str ;
			str += c;
			st.push(str);
		}
	}
	return result;
}
string postfixToPrefix(string &s) {
	reverse(s.begin(), s.end());
	string ans = prefixToPostfix(s);
	reverse(ans.begin(), ans.end());
	return ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << postfixToPrefix(s);
	cin.get();
}