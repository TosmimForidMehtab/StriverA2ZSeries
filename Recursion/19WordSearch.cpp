#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================

// ================= BETTER ====================
bool solve(vector<vector<char>>& board, string word, int i, int j, int idx, vector<vector<bool>>& visited, int n, int m) {
	if (idx == word.length()) return true;

	if (i < 0 or i >= n or j < 0 or j >= m or board[i][j] != word[idx] or visited[i][j]) return false;

	visited[i][j] = true;
	bool top = solve(board, word, i - 1, j, idx + 1, visited, n, m);
	bool right = solve(board, word, i, j + 1, idx + 1, visited, n, m);
	bool bottom = solve(board, word, i + 1, j, idx + 1, visited, n, m);
	bool left = solve(board, word, i, j - 1, idx + 1, visited, n, m);
	visited[i][j] = false;

	return top or right or bottom or left;
}
bool exist(vector<vector<char>>& board, string word) {
	if (word == "") return false;
	int n = board.size(), m = board[0].size();
	int idx = 0;
	vector<vector<bool>> visited(n, vector<bool>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; j++) {
			if (solve(board, word, i, j, idx, visited, n, m)) return true;
		}
	}
	return false;
}
// ================= BEST ====================

int32_t main() {
	fast
	cout.setf(ios::boolalpha);

	int n, m;
	cin >> n >> m;
	string word;
	cin >> word;
	vector<vector<char>> arr(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << exist(arr, word);
	cin.get();
}