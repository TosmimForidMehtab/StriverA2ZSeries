#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
/* STEPS
    1. Make the LL circular and while doing that also calculate the length
    2. Go len-k nodes and also set k = k % length
    3. The current nodes next nodes is the head and set the current's next to NULL
    4. Return head
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
ListNode* rotateRight(ListNode* head, int k) {
	if (!head or !head->next or k == 0)
		return head;

	ListNode* curr = head;
	int len = 1;
	while (curr->next) {
		len++;
		curr = curr->next;
	}
	curr->next = head;
	k %= len;
	k = len - k;
	while (k--)
		curr = curr->next;
	head = curr->next;
	curr->next = NULL;
	return head;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}