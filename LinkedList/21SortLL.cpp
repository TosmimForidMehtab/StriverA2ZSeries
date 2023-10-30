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

//* Approach 1: Convert LL to array, sort it and then overwrite the LL and return head
ListNode* sortList(ListNode* head) {
	vector<int> LList;
	ListNode* temp = head;
	while (temp != NULL) {
		LList.push_back(temp->val);
		temp = temp->next;
	}

	sort(LList.begin(), LList.end());
	int i = 0;
	temp = head;
	while (temp != NULL) {
		temp->val = LList[i];
		// if (i == 0) head = temp;
		i++;
		temp = temp->next;
	}

	return head;
}

//* Approach 2: Merge Sort

// Find middle
ListNode* midPoint(ListNode* head) {
	if (head == NULL or head->next == NULL)
		return head;
	ListNode* slow = head;
	ListNode* fastt = head->next;

	while (fastt != NULL and fastt->next != NULL) {
		fastt = fastt->next->next;
		slow = slow->next;
	}

	return slow;
}

// Merge
ListNode* mergeSortedList(ListNode* head1, ListNode* head2) {
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	ListNode* ans = new ListNode(0);
	ListNode* curr = ans;

	while (head1 != NULL and head2 != NULL) {
		if (head1->val < head2->val) {
			curr->next = head1;
			head1 = head1->next;
		} else {
			curr->next = head2;
			head2 = head2->next;
		}

		curr = curr->next;
	}

	if (head1 != NULL) {
		curr->next = head1;
	} else if (head2 != NULL) {
		curr->next = head2;
	}

	return ans->next;
}

ListNode* sortList2(ListNode* head) {
	if (head == NULL or head->next == NULL)
		return head;
	ListNode* mid = midPoint(head);
	ListNode* newHead = mid->next;
	mid->next = NULL;

	ListNode* left = sortList(head);
	ListNode* right = sortList(newHead);

	return mergeSortedList(left, right);
}

int32_t main() {
	fast


	cout << endl;
	cin.get();
}