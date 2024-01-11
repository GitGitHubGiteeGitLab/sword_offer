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

     /**
        先层序遍历，再翻转偶数行
     */
    vector<vector<int> > Print(TreeNode* pRoot) {
        // write code here
        vector<vector<int>> ans;
        if(!pRoot){
            return ans;
        }
        queue<TreeNode *> que;
        que.push(pRoot);
        while(!que.empty()){
            int cnt = que.size();
            vector<int> tmp;
            for(int i = 0; i < cnt; i++){
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            ans.push_back(tmp);
        }
        for(int i = 1; i < ans.size(); i += 2){
            reverse(ans[i].begin(), ans[i].end());
        }      
        return ans;
    }
};