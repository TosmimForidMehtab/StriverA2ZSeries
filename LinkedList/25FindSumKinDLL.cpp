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

vector<pair<int, int>> findPairs(Node* head, int k) {
	vector<pair<int, int>> ans;
	Node* tail = head;
	while (tail->next)
		tail = tail->next;
	Node* curr = head;
	while (curr->data < tail->data) {
		if (curr->data + tail->data == k) {
			ans.push_back({curr->data, tail->data});
		}
		if (curr->data + tail->data > k) {
			tail = tail->prev;
		} else
			curr = curr->next;
	}
	return ans;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}