#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool cmp(int a, int b) {
	return b >= a;
}
string frequencySort(string s) {
	// Both ordered and unordered map work for the test cases
	unordered_map<char, int> mp;
	for (char ch : s)
		mp[ch]++;

	vector<pair<char, int>> vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
		return a.second > b.second;
	});
	string ans = "";
	for (auto& x : vec) {
		while (x.second--) {
			ans += x.first;
		}
	}
	return ans;
}
string frequencySort2(string s) {
	unordered_map<char, int> mp;
	for (auto i : s) {
		mp[i]++;
	}

	priority_queue<pair<int, char>> pq;
	for (auto i : mp) {
		pq.push({i.second, i.first});
	}

	int j = 0;
	while (!pq.empty()) {
		auto i = pq.top(); pq.pop();
		int temp = i.first;
		while (temp--) {
			s[j++] = i.second;
		}
	}

	return s;
}
int32_t main() {
	fast

	string s;
	cin >> s;
	cout << frequencySort2(s);
	cin.get();
}