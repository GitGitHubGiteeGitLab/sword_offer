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
     * @param sum int整型 
     * @return bool布尔型
     */
     /**
        sum - root->val == 0
            !root->left && !root->right
        sum - root->val != 0 
            递归sum -= root->val
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(root){
            sum -= root->val;
            if(sum == 0 && !root->left && !root->right){
                return true;
            }
            bool ret1 = hasPathSum(root->left, sum);
            bool ret2 = hasPathSum(root->right, sum);
            return ret1 || ret2;          
        }
        return false;
    }
};