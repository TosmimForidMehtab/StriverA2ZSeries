#include<bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int> bitManipulation(int num, int i) {
	// Get ith bit
	int ithBit = num >> (i - 1) & 1;
	// Set ith bit
	int setBit = 1 << (i - 1) | num;
	// Clear ith bit
	int clearBit = 1 << (i - 1) ^ setBit;
	return {ithBit, setBit, clearBit};
}
int32_t main() {
	fast

	int n, i;
	cin >> n >> i;
	vector<int> ans = bitManipulation(n, i);
	for (int x : ans)cout << x << " ";
	cin.get();
}