#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
bool cmp(const int a, const int b) {
	return a < b;
}
bool isValidBST(vector<int> &order) {
	// Write your code here.
	return is_sorted(order.begin(), order.end(), cmp);
}
// ================= BEST ====================

int32_t main() {
	fast


	cout << endl;
	cin.get();
}