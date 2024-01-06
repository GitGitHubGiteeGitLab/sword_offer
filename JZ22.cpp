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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        /**
            双指针：保持间距为k进行平移
            也可以用栈
        */
        // write code here
        ListNode *prev = pHead;
        ListNode *cur = pHead;
        while(k--){
            if(!cur){
                return nullptr;
            }
            cur = cur->next;
        }
        while(cur){
            cur = cur->next;
            prev = prev->next;
        }
        return prev;
    }
};