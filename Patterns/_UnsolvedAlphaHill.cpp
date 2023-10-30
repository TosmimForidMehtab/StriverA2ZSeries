#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main() {
	fast

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {

		// for printing the spaces.
		for (int j = 0; j < N - i - 1; j++) {
			cout << " ";
		}

		// for printing the characters.
		char ch = 'A';
		int breakpoint = (2 * i + 1) / 2;
		for (int j = 1; j <= 2 * i + 1; j++) {

			cout << ch;
			if (j <= breakpoint)
				ch++;
			else
				ch--;
		}

		// for printing the spaces again after characters.
		for (int j = 0; j < N - i - 1; j++) {
			cout << " ";
		}

		// As soon as the letters for each iteration are printed, we move to the
		// next row and give a line break otherwise all letters
		// would get printed in 1 line.
		cout << endl;

	}
	cout << endl;
	cin.get();
}