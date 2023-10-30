#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool isPossible(vector<int>& stalls, int mid, int cows) {
	int cowCount = 1;
	int last = stalls[0];
	for (int i = 1; i < stalls.size(); i++) {
		if (stalls[i] - last >= mid) {
			cowCount++;
			last = stalls[i];
		}
	}
	return cowCount >= cows;
}
int maxOfMinDist(vector<int>& stalls, int cows) {
	// Binary search has to be applied on the difference of elements. So, sorting is done
	sort(stalls.begin(), stalls.end());
	int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
	while (low <= high) {
		int mid = (low + high) / 2;
		if (isPossible(stalls, mid, cows))
			low = mid + 1;
		else
			high = mid - 1;
	}
	return high;
}
int32_t main() {
	fast

	int n, cows;
	cin >> n >> cows;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxOfMinDist(arr, cows);
	cin.get();
}