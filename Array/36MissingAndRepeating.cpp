#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> findMissingRepeatingNumbers(vector < int > a) {
	// Swap sort
	int n = a.size();
	for (int i = 0; i < n; i++) {
		int ele = a[i];
		if (ele > 0 and ele <= n) {
			int index = ele - 1;
			if (ele != a[index]) {
				swap(a[i], a[index]);
				i--;
			}
		}
	}

	int missing = 0, repeating = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != i + 1) {
			repeating = a[i];
			missing = i + 1;
		}
	}
	return { repeating, missing };
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ans = findMissingRepeatingNumbers(arr);
	cout << ans[0] << " " << ans[1] << endl;
	cin.get();
}