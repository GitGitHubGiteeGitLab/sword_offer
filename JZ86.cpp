/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */

     /**
        回溯：从下到上遍历
        后序遍历
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        //root为空
        if(root == nullptr){
            return -1;
        }
        //root->val与o1, o2其中一个匹配
        if(root->val == o1 || root->val == o2){
            return root->val;
        }

        //root->val与o1, o2均不匹配
        int left = lowestCommonAncestor(root->left, o1, o2);
        int right = lowestCommonAncestor(root->right, o1, o2);
        //root->left与root->right均非空，root就是lca
        if(left != -1 && right != -1){
            return root->val;
        }
        //left不为空，rifght为空, left为lca;
        if(left != -1){
            return left;
        }
 
        //right不为空，rifght为空, left为lca;
        if(right != -1){
            return right;
        }

        //left与right均为空，返回空
        return -1;
    }
};