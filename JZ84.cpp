
/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
     * @return int整型
     */
    int FindPath(TreeNode* root, int sum) {
        // write code here
        int num = 0;
        queue<TreeNode*> que;
        if (root == nullptr) {
            return 0;
        }
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            paths(node, sum, num);
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        return num;
    }

    void paths(TreeNode* root, int sum, int& num) {
        if (root == nullptr) {
            return;
        }
        if (root->val == sum) {
            num++;
            //不能return, 可能漏掉0
        }
        paths(root->left, sum - root->val, num);
        paths(root->right, sum - root->val, num);
    }
};