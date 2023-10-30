#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	explicit ListNode(int x): val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	ListNode* h1 = headA, *h2 = headB;
	while (h1 != h2) {
		h1 = (h1 == NULL) ? headB : h1->next;
		h2 = (h2 == NULL) ? headA : h2->next;
	}
	return h1;
    // 1->2->3->4->5
    // 2->3->4->7
}

int32_t main() {
	fast


	cout << endl;
	cin.get();
}