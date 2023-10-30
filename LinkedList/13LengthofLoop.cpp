#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
class Node {
  public:
	int data;
	Node* next;

	explicit Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

int lengthOfLoop(Node* head) {
	Node* slow = head, *fastt = head;
	while (fastt != NULL and fastt->next != NULL) {
		slow = slow->next;
		fastt = fastt->next->next;

		if (slow == fastt) {
			break;
		}
	}
	if (fastt == NULL or fastt->next == NULL) {
		return 0;
	}
	Node* curr = slow;
	int len = 0;
	while (curr->next != slow) {
		curr = curr->next;
		len++;
	}
	return len + 1;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}