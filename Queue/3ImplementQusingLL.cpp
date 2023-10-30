#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node() : data(0), next(nullptr) {}
	Node(int x) : data(x), next(nullptr) {}
	Node(int x, Node * next) : data(x), next(next) {}
};
struct Queue {
	Node* front;
	Node* rear;
	void push(int);
	int pop();
	Queue() {
		front = rear = NULL;
	}
};


void Queue::push(int x) {
	// Write Your Code Here
	Node *newNode = new Node(x);
	if (front == NULL) {
		front = rear = newNode;
		return;
	}

	rear->next = newNode;
	rear = newNode;
}

int Queue::pop() {
	// Write Your Code Here
	if (front == NULL) {
		return -1;
	}
	int ans = front->data;
	front = front->next;
	return ans;
}
int32_t main() {
	fast

	cout << endl;
	cin.get();
}