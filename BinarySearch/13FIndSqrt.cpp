#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int floorSqrt(int n) {
	int low = 0, high = n;
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (mid * mid == n) {
			return mid;
		}
		/* if (mid * mid <= n) {
		    low = mid + 1;
		} */
		if (mid * mid < n) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	// return high
	return ans;
}
// Calculating the floor of the square root with fractional part
float squareRoot(int number, int precision) {
	int start = 0, end = number;
	int mid;
	float ans;
	while (start <= end) {
		mid = (start + end) / 2;
		if (mid * mid == number) {
			ans = mid;
			break;
		}
		if (mid * mid < number) {
			start = mid + 1;
			ans = mid;
		} else {
			end = mid - 1;
		}
	}

	// For computing the fractional part
	// of square root upto given precision
	float increment = 0.1;
	for (int i = 0; i < precision; i++) {
		while (ans * ans <= number) {
			ans += increment;
		}

		// loop terminates when ans * ans > number
		ans = ans - increment;
		increment = increment / 10;
	}
	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	cout << floorSqrt(n) << endl;
	cin.get();
}