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
     * @param target int整型 
     * @return int整型vector<vector<>>
     */
     /**
        更新target:target -= root->val;
        tmp存储路径上节点的值，当到了叶子节点且root->val == tartget时
        ans.push_back(tmp); tmp.pop_back();
        递归返回当前节点时，tmp.pop_back();
     */
    vector<vector<int> > FindPath(TreeNode* root, int target) {
        // write code here
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        vector<int> tmp;
        paths(root, target, ans, tmp);
        return ans;
    }

    void paths(TreeNode *root, int target, vector<vector<int>>& ans, vector<int>& tmp){
        if(root == nullptr){
            return;
        }
        if(target == root->val && root->left == nullptr && root->right == nullptr){
            tmp.push_back(root->val);
            ans.push_back(tmp);
            tmp.pop_back();
        }
        tmp.push_back(root->val);
        paths(root->left, target - root->val, ans, tmp);
        paths(root->right, target - root->val, ans, tmp);
        tmp.pop_back();
    }
};