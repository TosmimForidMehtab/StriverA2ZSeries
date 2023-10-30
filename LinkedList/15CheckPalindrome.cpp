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

// Find Middle of Linked List
ListNode* findMid(ListNode* head) {
	if (!head or !head->next)
		return head;
	ListNode* slow = head, *fastt = head->next;
	while (fastt and fastt->next) {
		slow = slow->next;
		fastt = fastt->next->next;
	}
	return slow;
}

// Reveerse LL after mid
void reverseLL(ListNode*& head) {
	ListNode* prev = NULL, *curr = head, *later;
	while (curr) {
		later = curr->next;
		curr->next = prev;
		prev = curr;
		curr = later;
	}
	head = prev;
}

bool isPalindrome(ListNode* head) {
	ListNode* h1 = head;
	ListNode* mid = findMid(head);
	ListNode* h2 = mid->next;
	mid->next = NULL;
	reverseLL(h2);
	while (h1 and h2) {
		if (h1->val != h2->val) {
			return false;
		}
		h1 = h1->next;
		h2 = h2->next;
	}
	return true;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}