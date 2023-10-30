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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* fastt = dummy, *slow = dummy; //* dummy is used instead of head bcoz we want to stop at the node before the nth node
    for (int i = 0; i < n; i++) {
        fastt = fastt->next;
    }
    while (fastt->next) {
        fastt = fastt->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}