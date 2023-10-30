#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void addToStack(stack<int>& stack, int val) {
	if (stack.empty()) {
		stack.push(val);
		return;
	}
	int temp = stack.top();
	stack.pop();
	addToStack(stack, val);
	stack.push(temp);
}
void reverseStack(stack<int>& stack) {
	if (stack.empty())
		return;
	int temp = stack.top();
	stack.pop();
	reverseStack(stack);
	addToStack(stack, temp);
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}