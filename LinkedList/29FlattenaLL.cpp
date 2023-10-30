#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
  public:
	int data;
	Node* next;
	Node* child;
	Node() : data(0), next(nullptr), child(nullptr) {};
	explicit Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node* next, Node* child) : data(x), next(next), child(child) {}
};

Node* merge(Node* head, Node* right) {

	Node* ans = new Node(-1);
	Node* temp = ans;
	while (head != NULL && right != NULL) {
		if (head->data <= right->data) {
			temp->child = head;
			temp = head;
			head = head->child;
		} else {
			temp->child = right;
			temp = right;
			right = right->child;
		}
	}
	while (head != NULL) {
		temp->child = head;
		temp = head;
		head = head->child;
	}
	while (right != NULL) {
		temp->child = right;
		temp = right;
		right = right->child;
	}
	ans = ans->child;
	return ans;
}

Node* flattenLinkedList(Node* head) {
	if(!head or !head->next) return head;
	Node* right = flattenLinkedList(head->next);
	head->next = NULL;
	return merge(head, right);
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}