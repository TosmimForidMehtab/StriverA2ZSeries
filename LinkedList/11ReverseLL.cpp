#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	explicit ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
//* Iterative
ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL, *curr = head, *nextt;
	while (curr) {
		nextt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextt;
	}
	return prev;
}

//* Recursive
ListNode* reverseList(ListNode* head) {
	if (head == NULL or head->next == NULL)
		return head;

	// ListNode* headNext = head->next;
	ListNode* newHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}