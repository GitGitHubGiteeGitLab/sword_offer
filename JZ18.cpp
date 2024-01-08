/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here

        /**
            JZ76的简化版本
        */
        ListNode *newhead = nullptr;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur){
            ListNode *next = cur->next;
            while(cur && cur->val == val){
                next = cur->next;
                delete cur;
                cur = next;
            }
            if(newhead == nullptr){
                newhead = prev = cur;
                cur = next;
            }else{
                prev->next = cur;
                prev = cur;
                cur = next;
            }    
        }
        if(prev){
            prev->next = nullptr;
        }
        return newhead;
    }
};