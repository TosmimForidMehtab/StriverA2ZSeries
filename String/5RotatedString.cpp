#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
//* Finding something on string and preserving their order use concatenation of the input string
bool rotateString(string s, string goal) {
	int n = s.length();
	int m = goal.length();
	if (n != m)
		return false;
	string concatenatedS = s + s;
	if (concatenatedS.find(goal) != string::npos)
		return true;
	return false;

}

// Using Queue
bool rotateString2(string s, string goal) {
	int n = s.length();
	int m = goal.length();
	if (n != m)
		return false;

	queue<char> q1, q2;
	for (int i = 0; i < n; i++) {
		q1.push(s[i]);
	}
	for (int i = 0; i < m; i++) {
		q2.push(goal[i]);
	}

	int k = goal.length();
	while (k--) {
		if (q1 == q2)
			return true;
		char ch = q2.front();
		q2.pop();
		q2.push(ch);

	}
	return false;
}
// TODO: More optises
int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	string s, goal;
	cin >> s >> goal;
	cout << rotateString2(s, goal);
	cin.get();
}