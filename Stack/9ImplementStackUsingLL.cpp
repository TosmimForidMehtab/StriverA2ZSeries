#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		this->data = 0;
		next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}
};
class Stack {
	Node* head;
	int size;

	Stack() {
		head = NULL;
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void push(int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		size++;
	}

	void pop() {
		if (isEmpty()) return;
		Node *toPop = head;
		head = head->next;
		size--;
		delete toPop;
	}

	int getTop() {
		if (isEmpty()) return -1;
		return head->data;
	}
};
int32_t main() {
	fast

	cout << endl;
	cin.get();
}