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
ListNode* oddEvenList(ListNode* head) {
	if (!head or !head->next)
		return head;

	// evenHead is used to connect both the odd and even LL
	ListNode* odd = head, *even = head->next, *evenHead = even;
	while (even and even->next) {
		odd->next = odd->next->next;
		even->next = even->next->next;
		odd = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;
}
ListNode* evenOddList(ListNode* head) {
	if (!head or !head->next)
		return head;
	// Rearrange the LL such that the even nodes are placed before the odd nodes
	ListNode* dummyEven = new ListNode(-1);
	ListNode* dummyOdd = new ListNode(-1);
	ListNode* evenTail = dummyEven, *oddTail = dummyOdd, *curr = head;
	while (curr) {
		if (curr->val & 1) { //* Odd
			oddTail->next = curr;
			oddTail = oddTail->next;
		} else { //* Even
			evenTail->next = curr;
			evenTail = evenTail->next;
		}
		curr = curr->next;
	}
	evenTail->next = dummyOdd->next;
	oddTail->next = NULL; //* Very important. Else gives TLE
	return dummyEven->next;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}