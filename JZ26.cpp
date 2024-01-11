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
	/*
		两棵树有一棵树为空即为false
		当两个数均非空时：
			若根节点的值 == 二叉树B根节点的值，判断B是否是当前树的一部分
			否则分别判断B是否是左右子树的一部分
	*/
	bool isSubTree(TreeNode *root1, TreeNode *root2){
		if(!root1 && !root2){
			return true;
		}
		if(!root1){
			return false;
		}
		if(!root2){
			return true;
		}
		if(root1->val != root2->val){
			return false;
		}
		return isSubTree(root1->left, root2->left) && isSubTree(root1->right, root2->right);
	}

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if(!pRoot1 || !pRoot2){
			return false;
		}
		if(pRoot1->val == pRoot2->val){
			if(isSubTree(pRoot1, pRoot2)){
				return true;
			}
		}
		return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
