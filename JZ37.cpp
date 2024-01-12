/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
#include<cstring>
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(!root){
            return nullptr;
        }
        string s;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            TreeNode *node = que.front();
            que.pop();
            if(node == nullptr){
                s += "#,";
                continue;
            }
            s += to_string(node->val) + ",";
                   
            que.push(node->left); 
            que.push(node->right);
        
        }
        char* ans = new char[s.length() + 1];
        strcpy(ans, s.c_str());
        return ans;
    }
    TreeNode* Deserialize(char *str) {
        if(str == nullptr){
            return nullptr;
        }
        string s(str);
        queue<TreeNode *> nodes;
        TreeNode *root = new TreeNode(atoi(s.c_str()));
        s = s.substr(s.find_first_of(',') + 1);
        nodes. push(root);
        while(!nodes.empty() && !s.empty()){
            TreeNode *node = nodes.front();
            nodes.pop();
            if(s[0] == '#'){
                node->left = nullptr;
                s = s.substr(2);
            }else{
                node->left = new TreeNode(atoi(s.c_str()));
                nodes.push(node->left);
                s = s.substr(s.find_first_of(',') + 1);
            }
            if(s[0] == '#'){
                node->right = nullptr;
                s = s.substr(2);
            }else{
                node->right = new TreeNode(atoi(s.c_str()));
                nodes.push(node->right);
                s = s.substr(s.find_first_of(',') + 1);
            } 
        }
        return root;
    }
};