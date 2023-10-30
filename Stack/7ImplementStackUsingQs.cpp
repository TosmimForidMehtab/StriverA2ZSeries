#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class MyStack {
public:
	queue<int> q1;
	queue<int> q2;
	MyStack() {

	}

	void push(int x) {
		q1.push(x);
	}

	int pop() {
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		int x = q1.front();
		q1.pop();
		swap(q1, q2);
		return x;
	}

	int top() {
		return q1.back();
	}

	bool empty() {
		return q1.empty();
	}
};

int32_t main() {
	fast

	cout << endl;
	cin.get();
}