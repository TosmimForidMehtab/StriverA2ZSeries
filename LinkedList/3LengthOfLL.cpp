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
int length(Node* head) {
	//Write your code here
	int len = 0;
	Node* curr = head;
	while (curr != NULL) {
		len++;
		curr = curr->next;
	}
	return len;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}