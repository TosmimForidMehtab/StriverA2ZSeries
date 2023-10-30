#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int findMax(vector<int> arr, int end) {
	int maxi = 0;
	for (int i = 0; i < end; i++) {
		if (arr[i] > arr[maxi])
			maxi = i;
	}
	return maxi;
}
vector<int> findPeakGrid(const vector<vector<int>>& g) {
	int n = g.size();
	// g = [[65]]
	if (n == 1 and g[0].size() == 1)
		return {0, 0};
	// g = [[2,3,4,6]]
	if (n == 1)
		return {0, findMax(g[0], g[0].size())};

	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		int maxIndex = findMax(g[mid], g[mid].size());
		// * Corner case 1
		if (mid == 0 and mid + 1 < n) {
			if (g[mid][maxIndex] > g[mid + 1][maxIndex])
				return {mid, maxIndex};
		}
		// * Corner case 2
		if (mid == n - 1 and mid - 1 >= 0) {
			if (g[mid][maxIndex] > g[mid - 1][maxIndex])
				return {mid, maxIndex};
		}
		// * Main logic
		if (mid - 1 >= 0 and mid + 1 < n and g[mid][maxIndex] > g[mid - 1][maxIndex] and g[mid][maxIndex] > g[mid + 1][maxIndex])
			return {mid, maxIndex};

		if (mid + 1 < n and g[mid][maxIndex] < g[mid + 1][maxIndex])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return {-1, -1};
}
int32_t main() {
	fast

	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> ans = findPeakGrid(arr);
	cout << ans[0] << "," << ans[1];
	cin.get();
}