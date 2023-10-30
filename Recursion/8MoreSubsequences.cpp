#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
/* Create a function that generates the subsequences and pass both the strings one by one and compare the results
*/
// ================= BEST ====================
/*The string that has more distinct characters is the ans*/
string moreSubsequence(int n, int m, string a, string b)
{
	unordered_set<char> st1;
	unordered_set<char> st2;
	for (int i = 0; i < n; ++i)
	{
		st1.insert(a[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		st2.insert(b[i]);
	}
	if (st1.size() == st2.size()) return n < m ? b : a;
	return st1.size() > st2.size() ? a : b;
}
int32_t main() {
	fast

	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	cout << moreSubsequence(n, m, a, b);
	cin.get();
}