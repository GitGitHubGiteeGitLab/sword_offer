
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    /**
        三指针
    */
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode *prev = nullptr;
        ListNode *newhead = nullptr;
        ListNode *cur = pHead;
        ListNode *next = nullptr;
        while(cur){
            next = cur->next;
            //next may be empty
            if(next && cur->val == next->val){
                int val = cur->val;
                //delete the same val by loop
                while(cur && cur->val == val){
                    next = cur->next;
                    delete cur;
                    cur = next;
                }
                //cur points to another val, but we can't identify wheather the val repeats in the linked list several times or not;
            }else{
                if(prev == nullptr){
                    prev = newhead = cur;
                    cur = next;
                }else{
                    prev->next = cur;
                    prev = cur;
                    cur = next;
                }       
            }            
        }
        //in case that prev is not empty, prev is not the last in the original linked list
        if(prev){
            prev->next = nullptr;
        }
        return newhead;
    }
};