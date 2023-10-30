#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1, k = m + n - 1;
	while (i >= 0 and j >= 0) {
		if (nums1[i] > nums2[j]) {
			nums1[k] = nums1[i];
			i--;
			k--;
		} else {
			nums1[k] = nums2[j];
			j--;
			k--;
		}
	}

	while (i >= 0) {
		nums1[k] = nums1[i];
		i--;
		k--;
	}

	while (j >= 0) {
		nums1[k] = nums2[j];
		j--;
		k--;
	}

	return;
}

// Coding Ninjas version not solved
int32_t main() {
	fast


	cout << endl;
	cin.get();
}