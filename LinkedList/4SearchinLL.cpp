#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
template <typename T>
class Node {
  public:
	T data;
	Node<T>* next;
	Node() {
		this->data = 0;
		this->next = NULL;
	}
	explicit Node(T data) {
		this->data = data;
		this->next = NULL;
	}
	Node(T data, T* next) {
		this->data = data;
		this->next = next;
	}
};
int searchInLinkedList(Node<int>* head, int k) {
	// Write your code here.
	while (head != NULL) {
		if (head->data == k)
			return 1;
		head = head->next;
	}
	return 0;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}