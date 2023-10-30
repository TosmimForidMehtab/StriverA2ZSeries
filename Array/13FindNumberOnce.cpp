#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int search(int A[], int N) {
	int xorr = 0;
	for (int i = 0; i < N; i++) {
		xorr ^= A[i];
	}
	return xorr;
}
int32_t main() {
	fast

	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << search(A, N) << endl;
	cin.get();
}