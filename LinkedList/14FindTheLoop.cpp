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

ListNode* detectCycle(ListNode* head) {
	ListNode* slow = head, *fastt = head;
	while (fastt != NULL and fastt->next != NULL) {
		slow = slow->next;
		fastt = fastt->next->next;
		if (slow == fastt) {
			break;
		}
	}
	if (fastt == NULL or fastt->next == NULL) {
		return NULL;
	}
	slow = head;
	while (slow != fastt) {
		slow = slow->next;
		fastt = fastt->next;
	}
	return slow;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}