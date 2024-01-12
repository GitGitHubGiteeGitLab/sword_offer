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
     * @param pRoot TreeNode类 
     * @return bool布尔型
     */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        // write code here
        if(pRoot == nullptr){
            return true;
        }      
        bool flag = true;
        cal(pRoot, flag);
        return flag;
    }

    int cal(TreeNode *root, bool& flag){
        if(root == nullptr){
            return 0;
        }
        int left = cal(root->left, flag);
        int right = cal(root->right, flag);
        if(abs(left - right) > 1){
            flag = false;
        }
        return max(left, right) + 1;
    }
};