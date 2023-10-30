#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Parenthesis
// Precedence
int checkPrecedence(char ch) {
	if (ch == '^') return 3;
	if (ch == '*' or ch == '/') return 2;
	if (ch == '+' or ch == '-') return 1;
	return 0;
}
string infixToPrefix(string exp) {
	int n = exp.length();
	string ans = "";
	stack<char> st;
	for (int i = n - 1; i >= 0; i--)
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
	reverse(ans.begin(), ans.end());
	return ans;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << infixToPrefix(s);
	cin.get();
}