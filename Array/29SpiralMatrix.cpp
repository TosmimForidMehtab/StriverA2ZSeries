#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> ans;
	int top = 0, bottom = n - 1, left = 0, right = m - 1;

	while (left <= right && top <= bottom) {
		for (int i = left; i <= right; i++) {
			ans.push_back(matrix[top][i]);
		}
		top++;

		for (int i = top; i <= bottom; i++) {
			ans.push_back(matrix[i][right]);
		}
		right--;

		if (top <= bottom) {

			for (int i = right; i >= left; i--) {
				ans.push_back(matrix[bottom][i]);
			}
			bottom--;
		}

		if (left <= right) {

			for (int i = bottom; i >= top; i--) {
				ans.push_back(matrix[i][left]);
			}
			left++;
		}
	}

	return ans;
}

// TODO: Find the optimised approach
int findK(vector<vector<int>>& matrix, int n, int m, int k) {
	int top = 0, bottom = n - 1, left = 0, right = m - 1;
	vector<int> ans;
	while (left <= right && top <= bottom) {
		for (int i = left; i <= right; i++) {
			ans.push_back(matrix[top][i]);
		}
		top++;

		for (int i = top; i <= bottom; i++) {
			ans.push_back(matrix[i][right]);
		}
		right--;

		if (top <= bottom) {

			for (int i = right; i >= left; i--) {
				ans.push_back(matrix[bottom][i]);
			}
			bottom--;
		}

		if (left <= right) {

			for (int i = bottom; i >= top; i--) {
				ans.push_back(matrix[i][left]);
			}
			left++;
		}
	}

	if (ans[k - 1] == 0)
		return ans[1];
	return ans[k - 1];
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	/* vector<int> ans = spiralOrder(matrix);
	for (int i = 0; i < ans.size(); i++) {
	    cout << ans[i] << " ";
	} */

	cout << findK(matrix, n, m, 4);
	cin.get();
}