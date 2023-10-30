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

Node* insertAtFirst(Node* list, int newValue) {
	// Write your code here
	if (!list)
		return NULL;
	Node* newNode = new Node(newValue);
	newNode->next = list;
	list = newNode;
	return list;

}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}