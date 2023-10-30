#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int beautySum(string s) {
	int countt = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		int freq[26] = {0};
		for (int j = i; j < n; j++) {
			freq[s[j] - 'a']++;
			int maxFreq = INT_MIN, minFreq = INT_MAX;
			for (int k = 0; k < 26; k++) {
				if (freq[k] != 0) {
					maxFreq = max(maxFreq, freq[k]);
					minFreq = min(minFreq, freq[k]);
				}
			}
			countt += maxFreq - minFreq;
		}
	}
	return countt;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << beautySum(s);
	cin.get();
}