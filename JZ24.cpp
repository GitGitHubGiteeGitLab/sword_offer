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
     * @return ListNode类
     */
     //头插法实现链表逆置
    ListNode* ReverseList(ListNode* head) {
        // write code here
        if(!head){
            return nullptr;
        }
        ListNode *cur = head;
        ListNode *next = nullptr;
        ListNode *newhead = nullptr;
        while(cur){
            next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }
};