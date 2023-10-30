#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	stack<pair<int, int>> st;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0)
				st.push({i, j});
		}
	}

	while (!st.empty()) {
		pair<int, int> p = st.top();
		st.pop();

		for (int i = 0; i < m; ++i) {
			matrix[p.first][i] = 0;
		}

		for (int i = 0; i < n; ++i) {
			matrix[i][p.second] = 0;
		}
	}
}
// Most Optimised
vector<vector<int>> zeroMatrix1(vector<vector<int>>& matrix, int n, int m) {

	// int row[n] = {0}; --> matrix[..][0]
	// int col[m] = {0}; --> matrix[0][..]

	int col0 = 1;
	// step 1: Traverse the matrix and
	// mark 1st row & col accordingly:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				// mark i-th row:
				matrix[i][0] = 0;

				// mark j-th column:
				if (j != 0)
					matrix[0][j] = 0;
				else
					col0 = 0;
			}
		}
	}

	// Step 2: Mark with 0 from (1,1) to (n-1, m-1):
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i][j] != 0) {
				// check for col & row:
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
	}

	//step 3: Finally mark the 1st col & then 1st row:
	if (matrix[0][0] == 0) {
		for (int j = 0; j < m; j++) {
			matrix[0][j] = 0;
		}
	}
	if (col0 == 0) {
		for (int i = 0; i < n; i++) {
			matrix[i][0] = 0;
		}
	}

	return matrix;
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	setZeroes(arr);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cin.get();
}