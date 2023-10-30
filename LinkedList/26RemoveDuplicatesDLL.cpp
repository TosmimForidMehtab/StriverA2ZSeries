#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
  public:
	int data;
	Node* prev;
	Node* next;
	Node() {
		this->data = 0;
		this->prev = NULL;
		this->next = NULL;
	}
	explicit Node(int data) {
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
	Node(int data, Node* next, Node* prev) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};
Node* removeDuplicates(Node* head) {
	// Write your code here
	if (!head or !head->next) {
		return head;
	}

	Node* curr = head;
	while (curr->next) {
		if (curr->data == curr->next->data) {
			curr->next = curr->next->next;
		} else {
			curr = curr->next;
		}

	}
	return head;

}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}