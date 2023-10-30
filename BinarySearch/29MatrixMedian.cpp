#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// GFG
int findSmallerEle(vector<vector<int>>& matrix, int assumedMedian) {
	int noOfSmallerEle = 0;
	for (int i = 0; i < matrix.size(); i++) {
		int start = 0, end = matrix[i].size() - 1;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (matrix[i][mid] <= assumedMedian)
				start = mid + 1;
			else
				end = mid - 1;
		}
		noOfSmallerEle += start;
	}
	return noOfSmallerEle;
}
int median(vector<vector<int>>& matrix, int m, int n) {
	// low = min(column 1) and high = max(column n)
	/*
	    2 Nested BS used.
	    First BS : Finding Median
	    Second BS : Finding # of elements(k) <= N/2
	*/
	int N = m * n;
	int medianIndex = N / 2;
	int start = 1, end = 2000;
	while (start <= end) {
		int assumedMedian = start + (end - start) / 2;
		int smallerElements = findSmallerEle(matrix, assumedMedian);
		if (smallerElements <= medianIndex)
			start = assumedMedian + 1;
		else
			end = assumedMedian - 1;
	}
	return start;
}
// Todo
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
	cout << endl;
	cin.get();
}