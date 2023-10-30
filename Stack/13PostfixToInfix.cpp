#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string psotfixToInfixConversion(string &s) {
	int n = s.length();
	stack<string> st;
	for (int i = 0; i < n; i++)
	{
		if (isalnum(s[i])) {
			string str = string(1, s[i]);
			st.push(str);
		}
		else {
			string s1 = st.top();
			st.pop();
			string s2 = st.top();
			st.pop();

			string temp = '(' + s2 + s[i] + s1 + ')';
			st.push(temp);
		}
	}
	if (st.empty()) return "";
	return  st.top();
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << psotfixToInfixConversion(s);
	cin.get();
}