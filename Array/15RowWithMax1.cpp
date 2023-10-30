#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	int maxi = 0;
	int row = -1;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
		if (cnt > maxi) {
			maxi = cnt;
			row = i;
		}
	}
	return row;
}

void printAll(){
	cout<<"Hello";
}
int32_t main() {
	fast

	printAll();
	// int n, m;
	// cin >> n >> m;
	// vector<vector<int> > arr(n, vector<int>(m));
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cin >> arr[i][j];
	// 	}
	// }
	// cout << rowWithMax1s(arr, n, m) << endl;
	cin.get();
}
