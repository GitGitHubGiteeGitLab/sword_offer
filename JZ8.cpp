/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // 如果有右子树,一直找到右子树的最左下节点
        if(pNode->right){
            TreeLinkNode *rchild = pNode->right;
            while(rchild->left){
                rchild = rchild->left;
            }
            return rchild;
        }
        // 如果无右子树且当前结点是其父节点的左子结点，返回父节点
        if(pNode->next && pNode == pNode->next->left){
            return pNode->next;
        }        
        // 如果无右子树且当前结点是其父节点的右子节点
        //向上一直爬树，爬到当前结点是其父节点的左结点是自己为止
        if(pNode->next && pNode == pNode->next->right){
            TreeLinkNode *ancestor = pNode->next;
            while(ancestor->next && ancestor->next->left != ancestor){
                ancestor = ancestor->next;
            }
            return ancestor->next;
        }
        //负责通过编译
        return nullptr;
    }
};
