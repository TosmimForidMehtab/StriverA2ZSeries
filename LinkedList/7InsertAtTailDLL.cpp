#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
  public:
	int data;
	Node* next, *prev;
	Node() : data(0), next(nullptr), prev(nullptr) {}
	explicit Node(int x) : data(x), next(nullptr), prev(nullptr) {}
	Node(int x, Node* next, Node* prev) : data(x), next(next), prev(prev) {}
};
Node* insertAtTail(Node* head, int k) {
	// Write your code here
	Node* newNode = new Node(k);
	if (head == NULL) {
		return newNode;
	}
	Node* curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
	newNode->prev = curr;
	return head;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}