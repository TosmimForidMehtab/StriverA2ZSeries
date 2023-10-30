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

Node* constructLL(vector<int>& arr) {
	// Write your code here
	Node* head = new Node(arr[0]);
	Node* curr = head;
	for (int i = 1; i < arr.size(); i++) {
		curr->next = new Node(arr[i]);
		curr = curr->next;
	}
	return head;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}