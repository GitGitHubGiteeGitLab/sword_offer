/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ans;
		if(!root){
			return ans;
		}
		queue<TreeNode *> que;
		que.push(root);
		while(!que.empty()){
			TreeNode *node = que.front();
			que.pop();
			ans.push_back(node->val);
			if(node->left){
				que.push(node->left);
			}
			if(node->right){
				que.push(node->right);
			}
		}
		return ans;
    }
};
