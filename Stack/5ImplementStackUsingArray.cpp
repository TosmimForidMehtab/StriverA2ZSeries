#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// Stack class.
class Stack {

public:
	int n;
	int *arr;
	int topIndex;
	Stack(int capacity) {
		// Write your code here.
		this->n = capacity;
		arr = new int[n];
		topIndex = -1;
	}

	void push(int num) {
		// Write your code here.
		if (!isFull()) {
			topIndex++;
			arr[topIndex] = num;
		}
		else return;
	}

	int pop() {
		// Write your code here.
		if (!isEmpty()) {
			int a = arr[topIndex];
			topIndex--;
			return a;
		}
		return -1;
	}

	int top() {
		// Write your code here.
		if (topIndex == -1) return -1;
		return arr[topIndex];
	}

	int isEmpty() {
		// Write your code here
		if (topIndex == -1) return 1;
		return 0;
	}

	int isFull() {
		// Write your code here.
		if (topIndex == n - 1) return 1;
		return 0;
	}

};
int32_t main() {
	fast

	cout << endl;
	cin.get();
}