#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool search(const vector<int>& arr, int target) {
	int n = arr.size();
	int low = 0, high = n - 1;
	int ans = -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == target) {
			ans = mid;
			break;
		}
		if (arr[low] < arr[mid]) {
			if (target >= arr[low] && target <= arr[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} else if (arr[low] > arr[mid]) {
			if (target >= arr[mid] and target <= arr[high]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		} else
			low++;
	}
	return (ans != -1);
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}