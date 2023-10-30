#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ans(numRows, vector<int>(numRows));

	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j <= i; j++) {
			if (j == 0 or j == i) ans[i][j] = 1;

			else {
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
		}
		ans[i].resize(i + 1);
	}
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<vector<int>> ans = generate(n);
	for (auto ele : ans) {
		for (int x : ele) cout << x;
		cout << endl;
	}
	cin.get();
}