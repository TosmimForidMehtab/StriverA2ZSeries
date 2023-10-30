#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
bool isProper(string s) {
	int n = s.length();
	int point = -1;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == ')') {
			for (int j = i - 1; j > point; j--) {
				if (s[j] != '(') return false;
				point = i;
			}
		}
	}
	return true;
}
// ================= BETTER ====================
bool isValid(string s) {
	if (s.length() <= 1) {
		return false;
	}
	// Create unordered map
	unordered_map<char, char> um;
	stack<char> charStack;
	um.insert({'}', '{'});
	um.insert({')', '('});
	um.insert({']', '['});

	// If the first parntheses is a closing bracket
	if (um.count(s[0]))
	{
		return false;
	}
	// loop trough the strink if it's not a closing brack
	// then place it inside the stack
	for (int i = 0; i < s.length(); i++)
	{
		if (!um.count(s[i])) {
			charStack.push(s[i]);
		}
		else if (!charStack.empty() && charStack.top() == um[s[i]]) {
			charStack.pop();
		}
		else {
			return false;
		}

	}


	if (!charStack.empty())
		return false;
	return true;
}

// ================= BEST ====================
bool isBalanced(string s) {
	int len = s.length();
	stack<char> st;
	bool ans = true;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == '(') {
				st.pop();
			}
			else {
				ans = false;
				break;
			}
		}
		else if (s[i] == '}')
		{
			if (!st.empty() && st.top() == '{')
			{
				st.pop();
			}
			else
			{
				ans = false;
				break;
			}
		}
		else if (s[i] == ']')
		{
			if (!st.empty() && st.top() == '[')
			{
				st.pop();
			}
			else
			{
				ans = false;
				break;
			}
		}
	}
	if (!st.empty()) return false;
	return ans;
}
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	string s;
	cin >> s;
	cout << isProper(s);
	cin.get();
}