/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    /*
        顺序保存，再逆序
        当然也可用递归，递归到最深处再入数据并返回
        也可以用栈(先保存数据，再以相反的顺序取出来)
    */
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        if(!head){
            return ans;
        }
        ListNode *cur = head;
        while(cur){
            ans.push_back(cur->val);
            cur = cur->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};