#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
string reverseString(const string& str) {
	int n = str.length();
	string ans = "", word = "";
	stack<string> st;
	for (int i = 0; i < n; i++) {
		if (str[i] == ' ') {
			if (word.length() > 0) // For extra spaces
				st.push(word);
			word = "";
		} else {
			word += str[i];
		}
	}
	ans += word;
	while (!st.empty()) {
		ans += ' ' + st.top();
		st.pop();
	}
	// For starting space
	if (ans.length() != 0 and ans[0] == ' ')
		ans = ans.substr(1);
	return ans;
}

string reverseWords(string s) {
	stack<string> st;
	string ans = "";
	// Converting string to character
	char* conv = (char*)s.c_str();

	// Creating tokens
	char* token = strtok(conv, " ");
	while (token != NULL) {
		st.push(token);
		token = strtok(NULL, " ");
	}
	while (st.size() > 1) {
		ans += st.top() + " ";
		st.pop();
	}
	ans += st.top();
	st.pop();
	return ans;
}
int32_t main() {
	fast

	string s;
	getline(cin, s);
	cout << reverseString(s);
	cin.get();
}