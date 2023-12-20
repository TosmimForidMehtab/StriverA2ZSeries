#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ================= BRUTE ====================

// ================= BETTER ====================
void Solve(TreeNode* root, vector<int> &ans) {
	if (root == NULL) return;
	ans.push_back(root->val);
	Solve(root->left, ans);
	Solve(root->right, ans);
}
vector<int> preorderTraversalRec(TreeNode* root) {
	vector<int> ans;
	Solve(root, ans);
	return ans;
}
// ================= BEST ====================
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ans;
	if (root == NULL) return ans;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty()) {
		TreeNode* temp = st.top();
		st.pop();

		ans.push_back(temp->val);
		if (temp->right) {
			st.push(temp->right);
		}
		if (temp->left) {
			st.push(temp->left);
		}
	}
	return ans;
}
int32_t main() {
	fast


	cout << endl;
	cin.get();
}