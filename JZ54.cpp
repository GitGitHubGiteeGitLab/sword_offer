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
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    /**
        BST: 左小右边大， 压到一条直线上就是一个升序序列
        Preorder: 能把BST压平到一条直线上
    */
    void preorder(TreeNode *root, vector<int>& ans){
        if(root){
            preorder(root->left, ans);
            ans.push_back(root->val);
            preorder(root->right, ans);
        }
    }
    int KthNode(TreeNode* proot, int k) {
        // write code here
        vector<int> ans;
        preorder(proot, ans);
        if(!proot || k > ans.size() || k <= 0){
            return -1;
        }
        return ans[k - 1];
    }
};