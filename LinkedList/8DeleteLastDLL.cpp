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
Node* deleteLastNode(Node* head) {
	// Write your code here
	if (!head or !head->next) {
		return NULL;
	}
	Node* curr = head;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	Node* lastNode = curr->next;
	curr->next = NULL;
	lastNode->prev = NULL;
	delete lastNode;
	return head;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}