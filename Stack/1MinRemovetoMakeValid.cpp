#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string minRemoveToMakeValid(string s) {
	int n = s.size();
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			st.push(i);
		else if (s[i] == ')') {
			if (st.empty())
				s[i] = '#';
			else
				st.pop();
		}
	}
	// If anything remains in the stack, it has to be removed also
	while (!st.empty()) {
		s[st.top()] = '#';
		st.pop();
	}
	// Remove the #s from the string
	s.erase(remove(s.begin(), s.end(), '#'), s.end());
	return s;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << minRemoveToMakeValid(s);
	cin.get();
}