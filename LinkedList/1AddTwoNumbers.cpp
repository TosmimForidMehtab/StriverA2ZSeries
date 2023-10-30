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

class Solution {
  public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ansNode = new ListNode(-1);
		ListNode* head = ansNode;
		int carry = 0;
		while (l1 and l2) {
			int sum = l1->val + l2->val + carry;
			carry = sum / 10;
			ansNode->next = new ListNode(sum % 10);
			l1 = l1->next;
			l2 = l2->next;
			ansNode = ansNode->next;
		}
		// If l1 and l2 are of different lengths
		while (l1) {
			int sum = l1->val + carry;
			carry = sum / 10;
			ansNode->next = new ListNode(sum % 10);
			l1 = l1->next;
			ansNode = ansNode->next;
		}
		while (l2) {
			int sum = l2->val + carry;
			carry = sum / 10;
			ansNode->next = new ListNode(sum % 10);
			l2 = l2->next;
			ansNode = ansNode->next;
		}
		if (carry) {
			ansNode->next = new ListNode(carry);
		}
		return head->next;
	}
	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode(-1);
		ListNode* p = l1, *q = l2, *curr = ans;
		int carry = 0;
		while (p != NULL or q != NULL) {
			int x = (p != NULL) ? p->val : 0;
			int y = (q != NULL) ? q->val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			if (p != NULL)
				p = p->next;
			if (q != NULL)
				q = q->next;
		}
		if (carry > 0) {
			curr->next = new ListNode(carry);
		}
		return ans->next;
	}
};
int32_t main() {
	fast


	cout << endl;
	cin.get();
}