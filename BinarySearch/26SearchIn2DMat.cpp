#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool searchMatrix(vector<vector<int>>& mat, int target) {
	int n = mat.size();
	int m = mat[0].size();
	int i = 0, j = m - 1;
	while (i<n and j >= 0) {
		if (mat[i][j] == target)
			return true;
		if (mat[i][j] < target)
			i++;
		else
			j--;
	}
	return false;
}
int32_t main() {
	fast

	int n, m, target;
	cin >> n >> m >> target;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << endl;
	cin.get();
}