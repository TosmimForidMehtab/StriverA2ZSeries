#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
  public:
	int data;
	Node* next, *prev;
	Node() {
		this->data = 0;
		next = NULL;
		prev = NULL;
	}
	explicit Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
	Node(int data, Node* next, Node* prev) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};


Node* reverseDLL(Node* head) {
	// Given a doubly linked list. Reverse it
    // Write your code here
    if(!head or !head->next) return head;
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
	
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}