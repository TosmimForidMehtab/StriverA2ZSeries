#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans;
	ans.push_back(intervals[0]);
	for (int i = 1; i < n; i++) {
		if (intervals[i][0] <= ans.back()[1]) {
			ans.back()[1] = max(intervals[i][1], ans.back()[1]);
		} else
			ans.push_back(intervals[i]);
	}
	return ans;
}

vector<vector<int>> merge1(vector<vector<int>>& intervals) {
	vector<vector<int>> ans;
	if (intervals.size() == 0)
		return ans;
	sort(intervals.begin(), intervals.end());
	vector<int> temp = intervals[0];
	for (auto& it : intervals) {
		if (it[0] <= temp[1]) {
			temp[1] = max(it[1], temp[1]);
		} else {
			ans.push_back(temp);
			temp = it;
		}
	}
	ans.push_back(temp);
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> ans = merge(arr);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0] << " " << ans[i][1] << endl;
	}
	cin.get();
}