#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Modifying the array
int findDuplicate(vector<int>& nums) {
	int ind = 0;
	while (1) {
		int x = nums[ind];
		if (x == -1)
			return ind;
		nums[ind] = -1;
		ind = x;
	}
	return ind;
}

// Using slow fast pointer
int findDuplicate(const vector<int>& nums) {
	int slow = nums[0];
	int fastt = nums[0];
	do {
		slow = nums[slow];
		fastt = nums[nums[fastt]];
	} while (slow != fastt);
	fastt = nums[0];
	while (slow != fastt) {
		slow = nums[slow];
		fastt = nums[fastt];
	}
	return slow;
}

// Placing the elements in right place(Count sort)
int findDuplicate(vector<int>& arr) {
	int n = arr.size();
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int element = arr[i];
		if (element > 0 and element <= n) {
			int position = element - 1;


			if (element != arr[position]) {
				swap(arr[i], arr[position]);
				i--;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] != i + 1) {
			ans = arr[i];
		}
	}

	return ans;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}