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
     * @param preOrder int整型vector 
     * @param vinOrder int整型vector 
     * @return TreeNode类
     */

    /**
        先找到root, 左子树的节点个数是一定的， 右子树的节点个数也是一定的，递归构建左右子树
    */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        // write code here
        if(preOrder.size() == 0){
            return nullptr;
        }
        TreeNode *root = new TreeNode(preOrder[0]);
        vector<int> part_pre, part_in;
        int pos = 0;
        while(preOrder[0] != vinOrder[pos]){
            part_in.push_back(vinOrder[pos++]);
        }
        for(int i = 1; i <= pos; i++){
            part_pre.push_back(preOrder[i]);
        }
        root->left = reConstructBinaryTree(part_pre, part_in);
        part_pre.clear();
        part_in.clear();
        for(int i = pos + 1; i < preOrder.size(); i++){
            part_pre.push_back(preOrder[i]);
        }
        for(int i = pos + 1; i < vinOrder.size(); i++){
            part_in.push_back(vinOrder[i]);
        }
        root->right = reConstructBinaryTree(part_pre, part_in);
        return root;
    }
};