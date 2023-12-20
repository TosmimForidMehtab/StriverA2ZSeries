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
TreeNode* solve(TreeNode *root, int val) {
	if (root == nullptr) return nullptr;
	if (root->val == val) return root;
	if (root->val < val) return solve(root->right, val);
	return solve(root->left, val);
}
TreeNode* searchBST(TreeNode* root, int val) {
	return solve(root, val);
}
// ================= BEST ====================

int32_t main() {
	fast


	cout << endl;
	cin.get();
}