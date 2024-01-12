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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* head = nullptr;
		TreeNode* tail = nullptr;
		return build(pRootOfTree, head, tail);
    }

	TreeNode *build(TreeNode *root, TreeNode*& head, TreeNode*& tail){
		 //中序递归，叶子为空则返回
		if(root == nullptr){
			return root;
		}
		  //首先递归到最左最小值 
		build(root->left, head, tail);
		 //找到最小值，初始化head与pre
		if(head == nullptr){
			head = root;
			tail = root;
		}
		//当前节点与上一节点建立连接，将tail设置为当前值
		else{
			tail->right = root;
			root->left = tail;
			tail = root;
		}
		build(root->right, head, tail);
		return head;

	}
};
