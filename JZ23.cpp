
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
    /*
        判断有环后，进行两个调整：位置调整(slow) + 步频调整(fast)
    */
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *slow = pHead;
        ListNode *fast = pHead;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = pHead;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};