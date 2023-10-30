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
Node* reverseLL(Node* head) {
	if (!head or !head->next)
		return head;
	Node* prev = NULL, *curr = head, *later;
	while (curr) {
		later = curr->next;
		curr->next = prev;
		prev = curr;
		curr = later;
	}
	return prev;
}
Node* addOne(Node* head) {
	Node* newHead = reverseLL(head);
	Node* curr = newHead, *prev = NULL; // prev is used to contain the last node as after the while loop, curr will be NULL
	int carry = 0;
	while (curr) {
		int sum = 0;
		// Adding 1 to the first node only
		if (prev == NULL)
			sum = curr->data + 1;
		else
			sum = curr->data + carry;
		carry = sum / 10;
		curr->data = sum % 10;
		prev = curr;
		curr = curr->next;
	}
	if (carry)
		prev->next = new Node(carry);
	return reverseLL(newHead);
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}