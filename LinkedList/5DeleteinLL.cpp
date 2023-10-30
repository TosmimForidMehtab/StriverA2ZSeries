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
	explicit Node(int x) : data(x), next(nullptr) {}
	Node(int x, Node* next) : data(x), next(next) {}
};

Node* deleteNode(Node* list) {
	// Write your code here
	list->data = list->next->data;
	list->next = list->next->next;
	return list;
}

Node* deleteLast(Node* list) {
	// Write your code here
	if (!list || !list->next)
		return NULL;
	Node* curr = list;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	curr->next = NULL;
	return list;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}