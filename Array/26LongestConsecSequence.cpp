#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int longestConsecutive(vector<int>& nums) {
	int n = nums.size();
	unordered_set<int> st;
	for (int x : nums) st.insert(x);

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{

		int currElement = nums[i];
		int prevElement = currElement - 1;

		int cnt = 0;

		if (!st.count(prevElement)) {
			// Creating chain from current element
			while (st.count(currElement)) {
				currElement++;
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	return ans;
}

// GFG
int findLongestConseqSubseq(int arr[], int n)
{
	unordered_set<int> st;
	for (int i = 0; i < n; ++i)
	{
		st.insert(arr[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int currElement = arr[i];
		int prevElement = currElement - 1;

		int cnt = 0;
		if (!st.count(prevElement)) {
			while (st.count(currElement)) {
				currElement++;
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << findLongestConseqSubseq(arr, n);
	cin.get();
}