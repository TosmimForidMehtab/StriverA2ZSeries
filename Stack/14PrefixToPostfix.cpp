#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string prefixToInfixConversion(string &s) {
	int n = s.length();
	stack<string> st;
	for (int i = n - 1; i >= 0; i--)
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

			string temp = ')' + s2 + s[i] + s1 + '(';
			st.push(temp);
		}
	}
	if (st.empty()) return "";
	string ans = st.top();
	reverse(ans.begin(), ans.end());
	return ans;
}

int checkPrecedence(char ch) {
	if (ch == '^') return 3;
	if (ch == '*' or ch == '/') return 2;
	if (ch == '+' or ch == '-') return 1;
	return 0;
}
string infixToPostfix(string exp) {
	int n = exp.length();
	string ans = "";
	stack<char> st;
	for (int i = 0; i < n; ++i)
	{
		if (isalnum(exp[i])) ans += exp[i];
		else if (exp[i] == '(') st.push(exp[i]);
		else if (exp[i] == ')') {
			while (!st.empty() and st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			// Removing the '('
			st.pop();
		}
		else {
			// Check current character and stack top character's precedence
			while (!st.empty() and checkPrecedence(exp[i]) <= checkPrecedence(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	return ans;
}
string preToPost(string s) {
	string infix = prefixToInfixConversion(s);
	return infixToPostfix(infix);
}

// Better
string prefixToPostfix(string s) {
	int l = s.length();
	stack<string>st;
	string result = "";
	for (int i = l - 1; i >= 0; i--)
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
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << preToPost(s);
	cin.get();
}