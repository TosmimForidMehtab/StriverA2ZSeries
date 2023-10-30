#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ================= BRUTE ====================
vector<int> collidingAsteroids(vector<int> &asteroids)
{
	int collision = 0;
	int n = asteroids.size();
	vector<int> collided(n, 0);
	do {
		collision = 0;
		for (int i = 0; i < n - 1; i++) {
			if (asteroids[i] == 0 && i != 0) {
				collided[i] = 1;
				continue;
			}
			int start = -1;
			int end = -1;
			if (!collided[i]) {
				start = i;
				end = start + 1;
			}
			while (collided[end]) {
				end++;
			}

			if (asteroids[start] > 0 && asteroids[end] < 0) {
				if (asteroids[start] > abs(asteroids[end])) {
					collided[end] = 1;
				}
				else if (asteroids[start] == abs(asteroids[end])) {
					collided[start] = 1;
					collided[end] = 1;
				}
				else {
					collided[start] = 1;
				}
				collision = 1;
			}
		}
	} while (collision == 1);

	vector<int> res;
	if (asteroids[n - 1] == 0) collided[n - 1] = 1;
	for (int i = 0; i < n; i++) {
		if (!collided[i]) {
			res.push_back(asteroids[i]);
		}
	}
	return res;
}
// ================= BETTER ====================
vector<int> asteroidCollisionBetter(vector<int>& asteroids) {
	int n = asteroids.size();
	stack<int> st;
	for (int i = 0; i < n; ++i)
	{
		while (!st.empty() and asteroids[i] < 0 and st.top() > 0) {
			int sum = asteroids[i] + st.top();

			// If sum < 0, stack element affected else array element.
			if (sum < 0) st.pop();
			else if (sum > 0) {
				asteroids[i] = 0;
				// Break is optional asteroids[i] is now zero
				break;
			}
			else {
				st.pop();
				asteroids[i] = 0;
				// Break is optional asteroids[i] is now zero
				break;
			}
		}
		if (asteroids[i] != 0)
			st.push(asteroids[i]);
	}
	int stSz = st.size();
	vector<int> ans(stSz);
	int i = stSz - 1;
	while (!st.empty()) {
		ans[i--] = st.top();
		st.pop();
	}
	return ans;
}

// ================= BEST Codestudio+Leetcode ====================
vector<int> asteroidCollisionBest(vector<int>& asteroids) {
	int n = asteroids.size();
	vector<int> st;
	if (n > 0 && asteroids[0] == 0)
		st.push_back(0);

	for (int i = 0; i < n; ++i)
	{
		if (asteroids[i] == 0 && (i != 0 || !st.empty())) {
			continue;
		}
		bool isCollided = false;
		while (!st.empty() and asteroids[i] < 0 and st.back() > 0) {
			int sum = asteroids[i] + st.back();

			// If sum < 0, stack element affected else array element.
			if (sum < 0) st.pop_back();
			else if (sum > 0) {
				isCollided = true;
				break;
			}
			else {
				isCollided = true;
				st.pop_back();
				break;
			}
		}
		if (!isCollided)
			st.push_back(asteroids[i]);
	}
	return st;
}
// ======================Codestudio+Leetcode====================
vector<int> collidingAsteroidsBestest(vector<int> &asteroids) {
	stack<int> s;
	for (int i = 0; i < asteroids.size(); i++) {
		if (asteroids[i] > 0 || s.empty()) {
			s.push(asteroids[i]);
		} else {
			while (!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
				s.pop();
			}
			if (!s.empty() && s.top() == abs(asteroids[i])) {
				s.pop();
			} else if (s.empty() || s.top() <= 0) {
				s.push(asteroids[i]);
			}
		}
	}

	int n = s.size();
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = s.top();
		s.pop();
	}

	return ans;
}
int32_t main() {
	fast

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	vector<int> ans = asteroidCollisionBest(arr);
	for (int ele : ans) cout << ele << " ";
	cin.get();
}