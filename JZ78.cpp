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
     * @return int整型vector<vector<>>
     */
    /*
        深搜实现层序遍历
    */
    vector<vector<int> > Print(TreeNode* pRoot) {
        // write code here
        vector<vector<int>> ans;
        int k = 0;
        dfs(pRoot, ans, k);
        return ans;
    }

    void dfs(TreeNode *root, vector<vector<int>>& ans, int k){
        if(root == nullptr){
            return;
        }
        if(ans.size() == k){
            vector<int> tmp;
            ans.push_back(tmp);
        }
        ans[k].push_back(root->val);
        dfs(root->left, ans, k+1);
        dfs(root->right, ans, k+1);
        return;
    }
};