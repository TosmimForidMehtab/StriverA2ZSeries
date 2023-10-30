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

Node* deleteAllOccurrences(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == k) {
        return deleteAllOccurrences(head->next, k);
    }
    head->next = deleteAllOccurrences(head->next, k);
    return head;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}