#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
  public:
	int val;
	Node* next;
	Node* random;

	explicit Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
Node* copyRandomList(Node* head) {
	if (!head)
		return head;
	Node* newHead = new Node(0);
	Node* newCurr = newHead, *curr = head;
	unordered_map<Node*, Node*> mp;
	while (curr) {
		Node* temp = new Node(curr->val);
		mp[curr] = temp;
		newCurr->next = temp;
		newCurr = newCurr->next;
		curr = curr->next;
	}
	curr = head;
	newCurr = newHead->next;
	while (curr) {
		Node* random = mp[curr->random];
		newCurr->random = random;
		newCurr = newCurr->next;
		curr = curr->next;
	}
	return newHead->next;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}