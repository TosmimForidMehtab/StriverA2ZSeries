#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int matSearch(const vector <vector <int>>& mat, int N, int M, int X) {
	int i = 0, j = M - 1;
	while (i < N && j >= 0) {
		if (mat[i][j] == X) {
			return 1;
		} else if (mat[i][j] > X) {
			j--;
		} else {
			i++;
		}
	}
	return 0;
}
int32_t main() {
	fast

	int n, m, x;
	cin >> n >> m >> x;
	vector <vector <int>> mat(n, vector <int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	cout << matSearch(mat, n, m, x) << endl;
	cin.get();
}