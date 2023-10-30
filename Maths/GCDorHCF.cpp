#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<long long> lcmAndGcd1(long long A, long long B) {
	vector<long long> ans;
	long long gcd = __gcd(A, B);
	long long lcm = A * B / gcd;
	ans.push_back(lcm);
	ans.push_back(gcd);
	return ans;
}

vector<long long> lcmAndGcd2(long long A, long long B) {
	long long gcd = 1;
	for (int i = 1; i <= min(A, B); i++) {
		if (A % i == 0 && B % i == 0) {
			gcd = i;
		}
	}
	long long lcm = A * B / gcd;
	return {lcm, gcd};
}

long long findGcd(long long A, long long B) {
	if (B == 0)
		return A;

	return findGcd(B, A % B);
}

vector<long long> lcmAndGcd3(long long A, long long B) {
	long long gcd = findGcd(A, B);
	long long lcm = A * B / gcd;
	return {lcm, gcd};
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << endl;
	cin.get();
}