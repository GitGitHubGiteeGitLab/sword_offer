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
    int TreeDepth(TreeNode* pRoot) {
		if(!pRoot){
        return 0;
		}
		int h_left = TreeDepth(pRoot->left);
		int h_right = TreeDepth(pRoot->right);
		return (h_left > h_right) ? (h_left + 1) : (h_right + 1);
    }
};
