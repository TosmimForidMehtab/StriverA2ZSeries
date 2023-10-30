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
ListNode* deleteMiddle(ListNode* head) {
	if (!head or !head->next)
		return NULL;
	ListNode* slow = head, *fastt = head->next;
	while (fastt and fastt->next) {
		fastt = fastt->next->next;
		if (!fastt)
			break;
		slow = slow->next;
	}
	ListNode* nodeToDel = slow->next;
	slow->next = slow->next->next;
	nodeToDel->next = NULL;
	delete nodeToDel;
	return head;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}