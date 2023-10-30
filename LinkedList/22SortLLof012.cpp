#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
  public:
	int data;
	Node* next;
	Node() {
		this->data = 0;
		next = NULL;
	}
	explicit Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}
};
//* Same concept as even-odd linked list
Node* sortList(Node* head) {
	if (!head or !head->next)
		return head;
	Node* dummyZero = new Node(-1);
	Node* dummyOne = new Node(-1);
	Node* dummyTwo = new Node(-1);

	Node* zero = dummyZero, *one = dummyOne, *two = dummyTwo;
	Node* curr = head;
	while (curr) {
		if (curr->data == 0) {
			zero->next = curr;
			zero = zero->next;
		} else if (curr->data == 1) {
			one->next = curr;
			one = one->next;
		} else {
			two->next = curr;
			two = two->next;
		}
		curr = curr->next;
	}

	zero->next = dummyOne->next ? dummyOne->next : dummyTwo->next;
	one->next = dummyTwo->next;
	two->next = NULL;
	return dummyZero->next;
}

int32_t main() {
	fast


	cout << endl;
	cin.get();
}