#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

/* STEPS
    1. Find the length of the LL
    2. Reverse the first K group
    3. If there are nodes after this k nodes, send them in the recurive function to reverse them
    4. Return prev
    NOTE: Increment countt while reversing inside the loop
 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	explicit ListNode(int x) {
		val = x;
		next = NULL;
	}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int findLength(ListNode* head) {
	int len = 0;
	ListNode* curr = head;
	while (curr) {
		len++;
		curr = curr->next;
	}
	return len;
}

ListNode* reverseLL(ListNode* head, int k, int len) {
	if (k > len)
		return head;

	ListNode* prev = NULL, *curr = head, *later = NULL;
	int countt = 0;
	while (curr and countt < k) {
		later = curr->next;
		curr->next = prev;
		prev = curr;
		curr = later;
		countt++;
	}

	// If there are nodes after this k nodes, send them in the recurive function to reverse them
	if (later) {
		head->next = reverseLL(later, k, len - k);
	}

	return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
	int len = findLength(head);
	return reverseLL(head, k, len);
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}