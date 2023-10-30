// CPP program to answer queries for count of
// primes in given range.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
int prefix[MAX + 1];

void buildPrefix() {
	bool prime[MAX + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= MAX; p++) {

		// If prime[p] is not changed, then
		// it is a prime
		if (prime[p] == true) {

			// Update all multiples of p
			for (int i = p * 2; i <= MAX; i += p)
				prime[i] = false;
		}
	}

	// Build prefix array
	prefix[0] = prefix[1] = 0;
	for (int p = 2; p <= MAX; p++) {
		prefix[p] = prefix[p - 1];
		if (prime[p])
			prefix[p]++;
	}
}

int query(int L, int R) {
	return prefix[R] - prefix[L - 1];
}

// Driver code
int main() {
	buildPrefix();

	int l, r;
	cin >> l >> r;
	cout << query(l, r) << endl;
	return 0;
}
